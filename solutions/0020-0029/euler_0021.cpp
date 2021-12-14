#include <cmath>
#include <iostream>

#define MAX_N 10001

int main(int argc, char** argv) {
    int sum_factors[MAX_N];

    for (int i = 1; i < MAX_N; ++i) {
        sum_factors[i] = 1;
        int sqrt = std::floor(std::sqrt(i));
        for (int j = 2; j <= sqrt; ++j) {
            if (i % j == 0) {
                sum_factors[i] += j;
                if (j * j != i) sum_factors[i] += i / j;
            }
        }
    }

    int amicable = 0;
    for (int i = 1; i < MAX_N; ++i) {
        int j = sum_factors[i];
        if (j > i && j < MAX_N && sum_factors[j] == i) {
            amicable += i + j;
        }
    }

    std::cout << amicable << std::endl;

    return 0;
}