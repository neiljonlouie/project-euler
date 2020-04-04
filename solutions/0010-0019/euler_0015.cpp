#include <iostream>

long long grid[21][21] = {0};

long long count(int x, int y) {
    if (grid[x][y] != 0) return grid[x][y];

    if (x == 0 || y == 0) {
        grid[x][y] = 1;
        return 1;
    }

    grid[x][y] = count(x, y - 1) + count(x - 1, y);
    return grid[x][y];
}

int main(int argc, char **argv) {
    std::cout << count(20, 20) << std::endl;
}