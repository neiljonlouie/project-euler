#include <fstream>
#include <iostream>

int length(unsigned int num) {
    int length = 0;
    do {
        length++;
        num /= 10;
    } while(num != 0);

    return length;
}

int main(int argc, char **argv) {
    std::ifstream in("input_files/euler_0013.txt");

    int count[50][10] = {0};

    std::string str;
    for (int i = 0; i < 100; i++) {
        in >> str;
        for (int j = 0; j < 50; j++) {
            count[j][str[j] - '0']++;
        }
    }

    int digits[50] = {0};
    int carry = 0;
    for (int i = 49; i >= 0; i--) {
        digits[i] = carry;
        for (int j = 1; j < 10; j++) {
            digits[i] += count[i][j] * j;
        }

        carry = digits[i] / 10;
        digits[i] %= 10;
    }

    std::cout << carry;
    for (int i = 0; i < 10 - length(carry); i++) {
        std::cout << digits[i];
    }
    std::cout << std::endl;
}