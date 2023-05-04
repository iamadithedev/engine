project(Resources)

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC .)
target_precompile_headers(${PROJECT_NAME}  PRIVATE stl.hpp)
target_link_libraries(${PROJECT_NAME}      PRIVATE Graphics Assets Math assimp stb)

target_sources(${PROJECT_NAME} PRIVATE mesh_importer.cpp texture_importer.cpp)