#include <fstream>
#include <iostream>

#define SIZE 20

int main(int argc, char **argv) {
    std::ifstream in("input_files/euler_0011.txt");

    int grid[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            in >> grid[i][j];
        }
    }

    int down = 1, diag_left = 1, diag_right = 1, right = 1;
    int max = 0;
    for (int i = 0; i < SIZE - 4; i++) {
        for (int j = 0; j < SIZE - 4; j++) {
            down = grid[i][j];
            diag_left = grid[i + 3][j];
            diag_right = grid[i][j];
            right = grid[i][j];

            for (int k = 1; k <= 3; k++) {
                down *= grid[i + k][j];
                diag_left *= grid[i + 3 - k][j + k];
                diag_right *= grid[i + k][j + k];
                right *= grid[i][j + k];
            }

            if (down > max) max = down;
            if (diag_left > max) max = diag_left;
            if (diag_right > max) max = diag_right;
            if (right > max) max = right;
        }
    }

    std::cout << max << std::endl;
}