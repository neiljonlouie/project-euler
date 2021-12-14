#include <iostream>
#include <boost/multiprecision/gmp.hpp>

#define N 100

using boost::multiprecision::mpz_int;

int main(int argc, char **argv) {
    mpz_int factorial{1};
    for (int i = 2; i <= N; ++i) {
        factorial *= i;
    }

    int sum = 0;
    while (factorial != 0) {
        sum += (int)(factorial % 10);
        factorial /= 10;
    }

    std::cout << sum << std::endl;

    return 0;
}