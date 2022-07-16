#include "raylib.h"
#include <chrono>

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

using highClock = std::chrono::high_resolution_clock;

namespace rayon {
namespace core {
    /**
     * @brief Clock class
     * @details Handle the Clock
     */
    class Clock {
    public:
        /**
         * @brief Construct a new Clock object
         *
         */
        Clock() = default;
        /**
         * @brief Destroy the Clock object
         *
         */
        ~Clock() = default;
        /**
         * @brief Get the Elapsed Time object
         *
         * @return double
         */
        double getElapsedTime(void);
        /**
         * @brief Restart the Clock
         *
         */
        void restart(void);

    protected:
    private:
        /**
         * @brief Starting time point
         *
         */
        std::chrono::time_point<highClock> _started = highClock::now();
    };
}
}

#endif /* !CLOCK_HPP_ */
