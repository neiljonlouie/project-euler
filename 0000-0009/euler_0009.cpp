#include <iostream>

void generate_triplet(int m, int n, int& a, int& b, int &c) {
    a = m * m - n * n;
    b = 2 * m * n;
    c = m * m + n * n;
}

int main(int argc, char **argv) {
    int a, b, c, d, desired = 1000;
    bool done = false;
    for (int n = 1; n <= 25; n++) {
        for (int m = n + 1; m <= 25; m++) {
            d = 1;
            generate_triplet(m, n, a, b, c);
            while (d * (a + b + c) <= 1000) {
                if (d * (a + b + c) == 1000) {
                    std::cout << d * a << ", " << d * b << ", " << d * c
                              << std::endl;
                    std::cout << (d * a) * (d * b) * (d * c) << std::endl;
                    done = true;
                    break;
                }

                d++;
            }

            if (done) break;
        }

        if (done) break;
    }

    return 0;
}