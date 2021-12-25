#include <iostream>

#define MAX 1000

int length[MAX];

int get_length(int i) {
    if (i < 0 || i >= MAX) return -1;
    if (length[i] >= 0) return length[i];

    int len = 1, curr = 10;
    while (curr % i != 1) {
        curr = (curr % i) * 10;
        len++;
    }

    length[i] = len;
    return len;
}

int main(int argc, char** argv) {
    for (int i = 1; i < MAX; ++i) {
        length[i] = -1;
    }

    int idx = 0, max = -1;
    for (int i = 1; i < MAX; ++i) {
        int curr = i;
        while (curr % 2 == 0) curr /= 2;
        while (curr % 5 == 0) curr /= 5;
        if (curr == 1) {
            length[i] = 0;
            continue;
        }

        length[i] = get_length(curr);
        if (length[i] > max) {
            max = length[i];
            idx = i;
        }
    }

    std::cout << idx << std::endl;

    return 0;
}