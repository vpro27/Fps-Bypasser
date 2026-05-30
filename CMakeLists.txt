cmake_minimum_required(VERSION 3.25)
project(fpsbypasser)

# Force CMake to look into the exact default folder where the Geode CLI installs the SDK on GitHub Linux runners
list(APPEND CMAKE_PREFIX_PATH "/home/runner/.geode/sdk")

find_package(Geode REQUIRED)

add_geode_mod(com.developer.fpsbypasser
    VERSION 1.0.0
    ANDROID
)

target_sources(com.developer.fpsbypasser PRIVATE main.cpp)
