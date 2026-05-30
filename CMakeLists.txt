cmake_minimum_required(VERSION 3.25)
project(fpsbypasser)

# Point explicitly to the recursively cloned folder
set(GEODE_SDK_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk")

# Register the exact layout paths where the repository stores its cmake includes
list(APPEND CMAKE_PREFIX_PATH "${GEODE_SDK_ROOT}")
list(APPEND CMAKE_MODULE_PATH "${GEODE_SDK_ROOT}/loader/cmake")

# Target the configuration files inside the source framework tree
if(EXISTS "${GEODE_SDK_ROOT}/loader/cmake/GeodeMod.cmake")
    include("${GEODE_SDK_ROOT}/loader/cmake/GeodeMod.cmake")
else()
    message(FATAL_ERROR "Geode directory found, but tracking submodules are missing inside ${GEODE_SDK_ROOT}/loader/cmake/")
endif()

add_geode_mod(com.developer.fpsbypasser
    VERSION 1.0.0
    ANDROID
)

target_sources(com.developer.fpsbypasser PRIVATE main.cpp)
