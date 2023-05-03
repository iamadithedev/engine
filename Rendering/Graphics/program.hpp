#pragma once

#include "shader.hpp"

class Program final : public Object
{
public:
    void create()  final;
    void destroy() final;

    void bind() const;
    void link() const;

    void attach(const Shader* shader) const;
    void detach(const Shader* shader) const;

private:
    void status() const;
};