#include <iostream>
#include <vector>

#include "util.h"

#define MAX 1000

int main(int argc, char** argv) {
    std::vector<int> primes;
    std::vector<bool> is_prime(MAX * MAX);
    generate_primes(primes, MAX * MAX);

    for (auto it = primes.begin(); it != primes.end(); ++it) {
        is_prime[*it] = true;
    }

    int max_n = 0, max_a = 0, max_b = 0;
    auto b = primes.begin();
    while (*b < MAX) {
        for (int a = 1 - *b; a < *b - 1; ++a) {
            int n = 0, curr;
            do {
                curr = n * n + n * a + *b;
                ++n;
            } while (curr >= 0 && curr < MAX * MAX && is_prime[curr]);

            if (n > max_n) {
                max_n = n;
                max_a = a;
                max_b = *b;
            }
        }

        ++b;
    }

    // std::cout << max_n - 1 << ", " << max_a << ", " << max_b << std::endl;
    std::cout << max_a * max_b << std::endl;

    return 0;
}