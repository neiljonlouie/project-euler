#include <iostream>
#define MAX_NUM 2000000

int length[MAX_NUM + 1] = {0};

int collatz(long num) {
    if (num <= MAX_NUM) {
        if (num == 1) {
            length[1] = 1;
            return 1;
        }

        if (length[num] != 0) return length[num];

        if (num % 2 == 0) {
            length[num] = 1 + collatz(num / 2);
        } else {
            length[num] = 1 + collatz(3 * num + 1);
        }

        return length[num];
    } else {
        if (num % 2 == 0) {
            return 1 + collatz(num / 2);
        } else {
            return 1 + collatz(3 * num + 1);
        }
    }
}


int main(int argc, char **argv) {
    int max = 0, curr = 0, temp = 0;
    for (int i = 1; i <= 1000000; i++) {
        temp = collatz(i);
        if (temp > max) {
            max = temp;
            curr = i;
        }
    }

    std::cout << curr << std::endl;
}