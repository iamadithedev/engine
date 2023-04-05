#pragma once

class Object
{
public:
    [[nodiscard]] uint32_t handle() const;

protected:
    uint32_t _handle;

    Object();
};