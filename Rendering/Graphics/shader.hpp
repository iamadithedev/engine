#pragma once

#include "shader_stage.hpp"

class Shader final : public Object
{
public:
    void create()  final;
    void destroy() final;

    void bind() const;
    void link() const;

    void attach(const ShaderStage* shader) const;
    void detach(const ShaderStage* shader) const;

private:
    void status() const;
};