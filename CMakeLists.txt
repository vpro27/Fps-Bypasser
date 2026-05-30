cmake_minimum_required(VERSION 3.25)
project(fps_bypasser)

find_package(geode REQUIRED)

add_geode_mod(fps_bypasser
    VERSION 1.0.0
    ANDROID
)

target_sources(fps_bypasser PRIVATE main.cpp)
