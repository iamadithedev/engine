#include "ray_result.hpp"

RayResult::RayResult()
    : _index { -1 }
{
}

void RayResult::set_index(int32_t index)
{
    _index = index;
}

int32_t RayResult::index() const
{
    return _index;
}

bool RayResult::hit() const
{
    return _index != -1;
}