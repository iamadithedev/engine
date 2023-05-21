#pragma once

#include "object.hpp"

class ShaderStage final : public Object
{
public:
    ShaderStage(std::string file, uint32_t type);

    void create()  final;
    void destroy() final;

    void source(const std::vector<std::byte>& content) const;
    void source(const std::vector<char>&      content) const;

private:
    void status() const;

    std::string _file;
    uint32_t    _type;
};