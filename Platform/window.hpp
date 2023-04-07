#pragma once

class Window
{
public:
    Window();

    bool create(const std::string& title, int32_t width, int32_t height);

    void update()  const;
    void destroy() const;

    [[nodiscard]] bool       closing() const;
    [[nodiscard]] GLFWwindow* handle() const;

private:
    GLFWwindow* _handle;
};