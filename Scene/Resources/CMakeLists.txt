project(Resources)

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC .)

target_precompile_headers(${PROJECT_NAME}  PRIVATE stl.hpp)
target_link_libraries(${PROJECT_NAME}      PRIVATE Common Graphics Assets Math assimp yaml-cpp stb)

target_sources(${PROJECT_NAME} PRIVATE Importers/mesh_importer.cpp Importers/texture_importer.cpp)
target_sources(${PROJECT_NAME} PRIVATE Containers/shader_container.cpp)
target_sources(${PROJECT_NAME} PRIVATE resource_manager.cpp)