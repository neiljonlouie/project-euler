#include <iostream>
#include "boost/multiprecision/cpp_int.hpp"

using namespace boost::multiprecision;

int main(int argc, char **argv) {
    cpp_int x = 1;
    for (int i = 0; i < 1000; i++) {
        x *= 2;
    }

    int sum = 0;
    while (x > 0) {
        sum += (int)(x % 10);
        x /= 10;
    }

    std::cout << sum << std::endl;

    return 0;
}