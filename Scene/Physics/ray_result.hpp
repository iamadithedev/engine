#pragma once

class RayResult
{
public:
    RayResult();

    void set_index(int32_t index);

    [[nodiscard]] int32_t index() const;
    [[nodiscard]] bool    hit()   const;

private:
    int32_t _index;
};