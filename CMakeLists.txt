cmake_minimum_required(VERSION 3.25)
project(fps-bypasser)

find_package(geode REQUIRED)

add_geode_mod(${PROJECT_NAME}
    VERSION 1.0.0
    ANDROID
)

target_sources(${PROJECT_NAME} PRIVATE main.cpp)
