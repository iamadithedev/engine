project(Components)

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC .)
target_precompile_headers(${PROJECT_NAME}  PUBLIC stl.hpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Math)
target_sources(${PROJECT_NAME}        PRIVATE transform.cpp camera.cpp light.cpp)