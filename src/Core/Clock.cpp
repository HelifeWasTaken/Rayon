#include "Rayon/Core/Clock.hpp"

namespace rayon {
namespace core {
    double Clock::getElapsedTime(void)
    {
        auto value
            = highClock::now().time_since_epoch() - _started.time_since_epoch();
        return std::chrono::duration_cast<std::chrono::milliseconds>(value)
            .count();
    }

    void Clock::restart(void) { *this = Clock(); }
}
}
