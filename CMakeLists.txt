cmake_minimum_required(VERSION 3.25)
project(fpsbypasser)

# Define the local source path explicitly
set(GEODE_SDK_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk")

# Bypass find_package completely by loading the internal build macros manually
if(EXISTS "${GEODE_SDK_ROOT}/loader/cmake/GeodeMod.cmake")
    message(STATUS "Found Geode build macros locally!")
    include("${GEODE_SDK_ROOT}/loader/cmake/GeodeMod.cmake")
else()
    message(FATAL_ERROR "Could not find Geode source at ${GEODE_SDK_ROOT}")
endif()

# Define your mod structure
add_geode_mod(com.developer.fpsbypasser
    VERSION 1.0.0
    ANDROID
)

target_sources(com.developer.fpsbypasser PRIVATE main.cpp)
