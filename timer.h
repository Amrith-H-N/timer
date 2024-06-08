//// Created by amrith on 6/8/2024.//

#ifndef MAIN_TIMER_H
#define MAIN_TIMER_H
#include <chrono>
#include <iostream>

class Timer {

public:
    Timer() {
        m_startTime = std::chrono::high_resolution_clock::now();
    }
    ~Timer() {

        stop();
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_stopTime;
    void stop() {
        m_stopTime = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTime).time_since_epoch().count();
        auto stop = std::chrono::time_point_cast<std::chrono::microseconds>(m_stopTime).time_since_epoch().count();
        auto duration = stop - start;
        std::cout << "time elapsed(us) : " << duration;
    }
};
#endif//MAIN_TIMER_H
