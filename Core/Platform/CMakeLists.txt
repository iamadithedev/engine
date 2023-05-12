project(Platform)

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC .)
target_compile_definitions(${PROJECT_NAME} PUBLIC GLFW_INCLUDE_NONE)

target_precompile_headers(${PROJECT_NAME}  PRIVATE stl.hpp)
target_link_libraries(${PROJECT_NAME}      PRIVATE Common Math glfw glad)

target_sources(${PROJECT_NAME} PRIVATE GLFW/platform.cpp GLFW/window.cpp GLFW/platform_factory.cpp GLFW/window_callbacks.cpp GLFW/input.cpp)
target_sources(${PROJECT_NAME} PRIVATE Windows/platform.cpp Windows/window.cpp Windows/platform_factory.cpp)
target_sources(${PROJECT_NAME} PRIVATE Base/window.cpp)
