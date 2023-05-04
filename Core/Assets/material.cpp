#include "material.hpp"

Material::Material(const rgb& diffuse)
    : _diffuse { diffuse }
{
}

void Material::diffuse(const rgb& diffuse)
{
    _diffuse = diffuse;
}

const rgb& Material::diffuse() const
{
    return _diffuse;
}
