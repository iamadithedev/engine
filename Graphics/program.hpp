#pragma once

#include "shader.hpp"

class Program : public Object
{
public:
    void create();
    void destroy();

    void bind() const;
    void link() const;

    void attach(const Shader* shader) const;
    void detach(const Shader* shader) const;

private:
    void status() const;
};