#include <iostream>

#define SIZE 1001

int main(int argc, char** argv) {
    int stride = (SIZE - 1) / 2;
    int sum = 1, curr = 1;
    for (int i = 1; i <= stride; ++i) {
        for (int j = 1; j <= 4; ++j) {
            curr += 2 * i;
            sum += curr;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}