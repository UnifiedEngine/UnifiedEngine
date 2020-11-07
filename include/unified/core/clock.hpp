#ifndef UNIFIED_CORE_CLOCK_HPP
#define UNIFIED_CORE_CLOCK_HPP

#include <unified/defines.hpp>
#include <unified/core/time.hpp>

UNIFIED_BEGIN_NAMESPACE

class Clock
{
public:

    Clock();

    Time get_elapsed_time() const _UNIFIED_NOEXCEPT;
    Time restart() _UNIFIED_NOEXCEPT;

protected:

    Time _timestamp;

};

UNIFIED_END_NAMESPACE

#endif
