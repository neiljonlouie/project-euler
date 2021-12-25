#include <iostream>

#include "boost/multiprecision/gmp.hpp"
#include "boost/multiprecision/number.hpp"

#define MAX 1000

namespace mpr = boost::multiprecision;

int main(int argc, char** argv) {
    mpr::mpz_int prev{1}, curr{0};
    
    int digits = 0, idx = 0;
    do {
        curr += prev;
        prev = curr - prev;
        idx++;

        digits = (int)mpr::floor(mpr::log10((mpr::mpf_float)curr)) + 1;
    } while (digits < MAX);

    std::cout << idx << std::endl;

    return 0;
}