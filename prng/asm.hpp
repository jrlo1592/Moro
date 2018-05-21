#ifndef ASM_H
#define ASM_H

#include <iostream>

inline uint64_t rotl(const uint64_t x, int k)   // This was changed to C++ because there is a great chance this code will become a rotl instruction.
{
	return (x << k) | (x >> (64 - k));
}



#if defined (_MSC_VER)
    inline uint64_t cpuTime() { return __rdtsc; }
#else

    inline uint64_t cpuTime()
    {
        uint64_t timeRet;

        asm(
        "rdtsc                  \n"
        "shlq $32, %%rax        \n"
        "shrd $32, %%rdx, %%rax"
        :"=rax"(timeRet)
        :
        : "%rdx");

        return timeRet + 1;
    }

#endif





    /*
    uint32_t timeLo, timeHi;

    asm(
    "rdtsc      "
    :"=eax"(timeLo), "=edx"(timeHi));

    timeRet = timeHi;
    timeRet <<= 32;
    timeRet ^= timeLo;
    return timeRet;
    */


#endif
