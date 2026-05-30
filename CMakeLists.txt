cmake_minimum_required(VERSION 3.25)
project(fpsbypasser)

# Tell CMake to search the exact folder where the Geode CLI just downloaded everything
list(APPEND CMAKE_PREFIX_PATH "$ENV{GEODE_SDK}")

find_package(Geode REQUIRED)

add_geode_mod(com.developer.fpsbypasser
    VERSION 1.0.0
    ANDROID
)

target_sources(com.developer.fpsbypasser PRIVATE main.cpp)
