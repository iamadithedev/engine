project(Math)

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC .)
target_precompile_headers(${PROJECT_NAME}  PUBLIC stl.hpp)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
target_link_libraries(${PROJECT_NAME}   PUBLIC glm)

target_sources(${PROJECT_NAME} PRIVATE vec4.cpp vec3.cpp vec2.cpp rgb.cpp)