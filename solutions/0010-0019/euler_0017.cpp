#include <iostream>

int main(int argc, char **argv) {
    int ones[10] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4};
    int tens_1[10] = {3, 6, 6, 8, 8, 7, 7, 9, 9, 9};
    int tens_2[10] = {0, 0, 6, 6, 5, 5, 5, 7, 7, 6};

    int sum = 0, h, t, o;
    for (int i = 1; i < 1000; i++) {
        h = i / 100;
        t = (i / 10) % 10;
        o = i % 10;

        if (h > 0) {
            sum += (ones[h] + 7);
            if (i % 100 > 0) sum += 3;
        }

        if (t == 1) {
            sum += tens_1[t];
        } else {
            sum += (tens_2[t] + ones[o]);
        }
    }

    sum += 11;
    std::cout << sum << std::endl;
}