//
// Created by Svetlana Matculevich on 26/06/2017.
//

#ifndef DEMOS_STOPWATCH_H
#define DEMOS_STOPWATCH_H

/** @brief A Stopwatch object can be used to measure execution time of
    code, algorithms, etc.

    This genericStopwatch can be initialized in two time-taking modes, CPU time
    and real time (wall time).

    - For wall time use the  \ref gsStopwatch typedef.

    - For CPU time use the \ref gsCPUStopwatch typedef.

    \tparam Clock clock (eg. system specific) to use for measuring the time.

    \ingroup Utils
*/


// includes for wall clocks
#if __cplusplus >= 201103L
#  include <chrono>
#elif defined(__linux__)
#  include <sys/time.h>
#elif defined(_MSC_VER) || defined(__MINGW32__)
#  include <sys/timeb.h>
#else
#  include <ctime>
#endif

// includes for CPU clocks
#if defined(__linux__)
#  include <sys/resource.h>
#else
#  include <ctime>
#endif

inline std::ostream& formatTime(std::ostream& , double );

template <typename Clock>
class genericStopwatch
{
public:
    genericStopwatch() { restart(); }

    /// Start taking the time
    void restart() { m_start = Clock::getTime(); }

    /// Return elapsed time
    double stop() const { return Clock::getTime() - m_start; }

    friend std::ostream& operator<< (std::ostream& os, const genericStopwatch& sw)
    { return formatTime(os, sw.stop()); }

private:
    genericStopwatch (const genericStopwatch&);
    genericStopwatch& operator=(const genericStopwatch&);

    double m_start;
}; // class genericStopwatch

// SYSTEM-SPECIFIC CPU CLOCKS //////////////////////////////////////////////////

#if defined(__linux__) // || defined(TARGET_OS_MAC)                     // LINUX //

// A non-portable, more expensive, but higher resolution CPU clock
// which also does not suffer from the short wrap-around time of
// CPUClock.
struct LinuxCPUClock
{
    static double getTime()
    {
        rusage ru;
        getrusage(RUSAGE_SELF, &ru);
        return ru.ru_utime.tv_sec + 1.0e-6*ru.ru_utime.tv_usec;
    }
};

/// @brief A stop-watch measuring CPU time
typedef genericStopwatch<LinuxCPUClock> cpuStopwatch;

#else                                                             // PORTABLE //

// A portable, but not very accurate CPU clock.  Note that on a
// typical Linux system, clock_t is just 4 bytes long and this will
// wrap around after about 36 min.
struct CPUClock
{
    static double getTime() { return (double) clock() / (double) CLOCKS_PER_SEC; }
};

/// @brief A stop-watch measuring CPU time
typedef genericStopwatch<CPUClock> cpuStopwatch;

#endif

#endif //DEMOS_STOPWATCH_H
