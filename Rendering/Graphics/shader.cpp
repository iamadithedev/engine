#include "shader.hpp"

Shader::Shader(std::string file, uint32_t type)
    : _file { std::move(file) }
    , _type { type }
{
}

void Shader::create()
{
    _handle = glCreateShader(_type);
}

void Shader::destroy()
{
    assert(glIsShader(_handle));

    glDeleteShader(_handle);
}

void Shader::source(const char* data) const
{
    glShaderSource(_handle, 1, &data, nullptr);
}

void Shader::compile() const
{
    glCompileShader(_handle);

    status();
}

void Shader::status() const
{
    int  success;
    char info[512];

    glGetShaderiv(_handle, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(_handle, 512, nullptr, info);

        std::cerr << std::format("shader compilation failed - {} \n{}", _file, info);
    }
}
