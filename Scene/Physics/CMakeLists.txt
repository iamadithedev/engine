project(Physics)

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${BULLET_PHYSICS_SOURCE_DIR}/src .)
target_precompile_headers(${PROJECT_NAME}  PUBLIC stl.hpp)
target_link_libraries(${PROJECT_NAME}      PUBLIC BulletCollision LinearMath PRIVATE Math)

target_sources(${PROJECT_NAME} PRIVATE physics.cpp physics_shapes.cpp)