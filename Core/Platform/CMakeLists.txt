project(Platform)

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC .)
target_precompile_headers(${PROJECT_NAME}  PUBLIC stl.hpp)
target_compile_definitions(${PROJECT_NAME} PUBLIC GLFW_INCLUDE_NONE)
target_link_libraries(${PROJECT_NAME}      PUBLIC glfw)

target_sources(${PROJECT_NAME} PRIVATE GLFW/platform.cpp GLFW/window.cpp GLFW/platform_factory.cpp)
target_sources(${PROJECT_NAME} PRIVATE Windows/platform.cpp Windows/window.cpp Windows/platform_factory.cpp)
target_sources(${PROJECT_NAME} PRIVATE Base/window.cpp Base/platform.cpp time.cpp)
