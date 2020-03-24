#ifndef TIME_H
#define TIME_H
#include <chrono>
    namespace lib

{
class time_taken
{
public:
    void start()
    {
        t1 = std::chrono::high_resolution_clock::now();
    }

    auto finish()
    {
        t2 = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    }

    time_taken()
    {
        start();
    }

private:
    std::chrono::high_resolution_clock::time_point t1;
    std::chrono::high_resolution_clock::time_point t2;
};
} // namespace lib
#endif // TIME_H
