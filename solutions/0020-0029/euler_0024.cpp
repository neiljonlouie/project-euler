#include <iostream>
#include <vector>

#define ORDER 1000000

int main(int argc, char** argv) {
    std::vector<char> items{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    std::vector<int> factorials(items.size());
    factorials[0] = 1;
    for (int i = 1; i < factorials.size(); ++i) {
        factorials[i] = i * factorials[i - 1];
    }

    int remaining = ORDER - 1;
    for (int i = factorials.size() - 1; i >= 0; --i) {
        int idx = remaining / factorials[i];
        std::cout << items[idx];
        items.erase(items.begin() + idx);
        remaining %= factorials[i];
    }
    std::cout << std::endl;

    return 0;
}