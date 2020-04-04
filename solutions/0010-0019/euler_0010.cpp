#include <iostream>
#include "../util.h"

int main(int argc, char **argv) {
    std::vector<int> primes;
    generate_primes(primes, 2000000);

    long long int sum = 0;
    for (std::vector<int>::const_iterator it = primes.begin(); it != primes.end(); ++it) {
        sum += *it;
    }

    std::cout << sum << std::endl;
}