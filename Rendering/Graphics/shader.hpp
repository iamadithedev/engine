#pragma once

#include "object.hpp"

class Shader final : public Object
{
public:
    Shader(std::string file, uint32_t type);

    void create()  final;
    void destroy() final;

    void source(const char* data) const;

private:
    void compile() const;
    void status()  const;

    std::string _file;
    uint32_t    _type;
};