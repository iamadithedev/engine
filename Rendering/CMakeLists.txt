project(Rendering)

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC .)
target_link_libraries(${PROJECT_NAME}      PUBLIC Graphics PRIVATE Math)

target_sources(${PROJECT_NAME} PRIVATE material.cpp mesh.cpp)