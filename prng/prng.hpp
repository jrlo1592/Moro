#include <iostream>
#include "asm.hpp"

using namespace std;

class prng
{
private:
    uint64_t p = 0;
    uint64_t s[16];


public:

    void seed()
    {
        s[0] = cpuTime();

        for(int i = 0; i < 16; i++) { s[i] = cpuTime() + (i << i); }
    }


    prng()
    {
        seed();
    }

    uint64_t get()
    {
        const uint64_t s0 = s[p];
        uint64_t s1 = s[p = (p + 1) & 15];
        s1 ^= s1 << 31; // a
        s[p] = s1 ^ s0 ^ (s1 >> 11) ^ (s0 >> 30);
        return s[p] * UINT64_C(1181783497276652981);
    }
};


