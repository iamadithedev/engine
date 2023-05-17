#include "shader.hpp"

void Shader::create()
{
    _handle = glCreateProgram();
}

void Shader::destroy()
{
    assert(glIsProgram(_handle));

    glDeleteProgram(_handle);
}

void Shader::bind() const
{
    glUseProgram(_handle);
}

void Shader::link() const
{
    glLinkProgram(_handle);

    status();
}

void Shader::attach(const ShaderStage* shader) const
{
    assert(shader != nullptr);

    glAttachShader(_handle, shader->handle());
}

void Shader::detach(const ShaderStage* shader) const
{
    assert(shader != nullptr);

    glDetachShader(_handle, shader->handle());
}

void Shader::status() const
{
    int  success;
    char info[512];

    glGetProgramiv(_handle, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(_handle, 512, nullptr, info);

        std::cerr << std::format("shader linking failed \n{}", info);
    }
}
