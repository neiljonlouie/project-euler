#include <cstdlib>
#include <iostream>
#include <limits>
#include "../util.h"

std::vector<int> primes;

int count_divisors(int num) {
    if (num == 1) return 1;

    for (std::vector<int>::const_iterator it = primes.begin(); 
         it != primes.end(); ++it) {
        if (*it == num) return 2;
    }

    int to_consider = 0;
    for (int i = 0; i < primes.size(); i++) {
        if (primes[i] * primes[i] >= num) {
            to_consider = i + 1;
            break;
        }
    }

    int* count = (int *)calloc(to_consider, sizeof(int));
    int ctr = 0;
    while (num > 1 && ctr < to_consider) {
        if (num % primes[ctr] == 0) {
            count[ctr]++;
            num /= primes[ctr];
        } else {
            ctr++;
        }
    }

    int num_divisors = 1;
    for (int i = 0; i < to_consider; i++) {
        if (count[i] > 0) {
            num_divisors *= (count[i] + 1);
        }
    }

    return num_divisors;
}

int main(int argc, char **argv) {
    generate_primes(primes, 50000);
    
    int curr = 0, ctr = 1;
    int num_divisors = 0;
    while (num_divisors < 500) {
        curr += ctr;
        ctr++;

        num_divisors = count_divisors(curr);
    }

    std::cout << curr << std::endl;
}