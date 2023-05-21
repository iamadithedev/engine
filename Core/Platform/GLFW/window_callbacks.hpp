#pragma once

#include "window.hpp"

namespace glfw
{
    class WindowCallbacks
    {
    public:
        WindowCallbacks() = delete;

        static void on_size(GLFWwindow*  handle, int32_t width, int32_t height);
        static void on_close(GLFWwindow* handle);

    private:
        static Window* get_window(GLFWwindow* handle);
    };
}