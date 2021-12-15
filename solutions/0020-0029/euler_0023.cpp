#include <cmath>
#include <iostream>
#include <vector>

#define MAX_N 28123

int main(int argc, char** argv) {
    int sum_factors[MAX_N + 1];
    bool is_sum[MAX_N + 1];
    std::vector<int> abundants;

    for (int i = 1; i <= MAX_N; ++i) {
        sum_factors[i] = 1;
        is_sum[i] = false;
        int sqrt = std::floor(std::sqrt(i));
        for (int j = 2; j <= sqrt; ++j) {
            if (i % j == 0) {
                sum_factors[i] += j;
                if (j * j != i) {
                    sum_factors[i] += i / j;
                }
            }
        }

        if (sum_factors[i] > i) {
            abundants.push_back(i);
        }
    }

    for (auto it1 = abundants.begin(); it1 != abundants.end(); ++it1) {
        for (auto it2 = it1; it2 != abundants.end(); ++it2) {
            if (*it1 + *it2 <= MAX_N) {
                is_sum[*it1 + *it2] = true;
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= MAX_N; ++i) {
        if (!is_sum[i]) sum += i;
    }
    std::cout << sum << std::endl;

    return 0;
}