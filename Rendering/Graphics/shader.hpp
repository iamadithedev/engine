#pragma once

#include "object.hpp"

class Shader : public Object
{
public:
    Shader(std::string file, uint32_t type);

    void create();
    void destroy();

    void source(const char* data) const;
    void compile()                const;

private:
    void status() const;

    std::string _file;
    uint32_t    _type;
};