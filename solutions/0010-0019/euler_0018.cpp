#include <iostream>

int main(int argc, char **argv) {
    int pyramid[15][15];
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j <= i; j++) {
            std::cin >> pyramid[i][j];
        }
    }

    for (int i = 13; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            pyramid[i][j] += pyramid[i + 1][j] > pyramid[i + 1][j + 1]
                ? pyramid[i + 1][j] : pyramid[i + 1][j + 1];
        }
    }

    std::cout << pyramid[0][0] << std::endl;
}