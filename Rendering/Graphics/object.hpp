#pragma once

class Object
{
public:
    virtual void create()  = 0;
    virtual void destroy() = 0;

    [[nodiscard]] uint32_t handle() const;

protected:
    uint32_t _handle;

    Object();
};