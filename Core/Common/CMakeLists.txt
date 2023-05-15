project(Common)

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC .)
target_precompile_headers(${PROJECT_NAME}  PUBLIC stl.hpp)

target_sources(${PROJECT_NAME} PRIVATE time.cpp)