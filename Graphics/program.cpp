#include "program.hpp"

void Program::create()
{
    _handle = glCreateProgram();
}

void Program::destroy()
{
    assert(glIsProgram(_handle));

    glDeleteProgram(_handle);
}

void Program::bind() const
{
    glUseProgram(_handle);
}

void Program::link() const
{
    glLinkProgram(_handle);

    status();
}

void Program::attach(const Shader* shader) const
{
    glAttachShader(_handle, shader->handle());
}

void Program::detach(const Shader* shader) const
{
    glDetachShader(_handle, shader->handle());
}

void Program::status() const
{
    int  success;
    char info[512];

    glGetProgramiv(_handle, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(_handle, 512, nullptr, info);

        std::cerr << std::format("program linking failed \n{}", info);
    }
}
