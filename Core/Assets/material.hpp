#pragma once

#include "rgb.hpp"

class Material
{
public:
    explicit Material(const rgb& diffuse);

    void diffuse(const rgb& diffuse);

    [[nodiscard]] const rgb& diffuse() const;

private:
    rgb _diffuse;
};