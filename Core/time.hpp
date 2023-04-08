#pragma

using time_clock = std::chrono::high_resolution_clock;
using time_point = std::chrono::time_point<time_clock>;

class Time
{
public:
    Time();

    float total_time() const;

private:
    time_point _offset;
};
