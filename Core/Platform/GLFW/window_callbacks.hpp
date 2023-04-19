#pragma once

namespace glfw
{
    class WindowCallbacks
    {
    public:
        static void on_size(GLFWwindow*  handle, int32_t width, int32_t height);
        static void on_close(GLFWwindow* handle);
    };
}