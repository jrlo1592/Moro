#include <iostream>
#include "prng.hpp"
#include "asm.hpp"

using namespace std;

int main()
{
    prng test;

    cout<< test.get() << endl;
    return 0;
}
