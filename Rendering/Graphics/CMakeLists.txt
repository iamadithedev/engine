project(Graphics)

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC .)
target_precompile_headers(${PROJECT_NAME}  PUBLIC stl.hpp)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
target_link_libraries(${PROJECT_NAME}   PUBLIC glad PRIVATE Common)

target_sources(${PROJECT_NAME} PRIVATE buffer.cpp buffer_data.cpp vertex_array.cpp shader.cpp program.cpp render_pass.cpp
                                       texture.cpp texture_data.cpp)