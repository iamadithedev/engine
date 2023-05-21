#include "shader_stage.hpp"

ShaderStage::ShaderStage(std::string file, uint32_t type)
    : _file { std::move(file) }
    , _type { type }
{
}

void ShaderStage::create()
{
    _handle = glCreateShader(_type);
}

void ShaderStage::destroy()
{
    assert(glIsShader(_handle));

    glDeleteShader(_handle);
}

void ShaderStage::source(const std::vector<std::byte>& content) const
{
    glShaderBinary(1, &_handle, GL_SHADER_BINARY_FORMAT_SPIR_V, content.data(), static_cast<int32_t>(content.size()));
    glSpecializeShader(_handle, "main", 0, nullptr, nullptr);
}

void ShaderStage::source(const std::vector<char>& content) const
{
    auto   size  = static_cast<int32_t>(content.size());
    auto   data  = content.data();
    assert(data != nullptr);

    glShaderSource(_handle, 1, &data, &size);
    glCompileShader(_handle);

    status();
}

void ShaderStage::status() const
{
    int  success;
    char info[512];

    glGetShaderiv(_handle, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(_handle, 512, nullptr, info);

        std::cerr << std::format("shader stage compilation failed - {} \n{}", _file, info);
    }
}
