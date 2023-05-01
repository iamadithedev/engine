#include "time.hpp"

Time::Time()
    : _offset { time_clock::now() }
{
}

float Time::total_time() const
{
    const  std::chrono::duration<float> difference = time_clock::now() - _offset;
    return difference.count();
}
