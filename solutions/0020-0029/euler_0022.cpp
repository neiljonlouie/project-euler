#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int get_score(std::string &name) {
    int score = 0;
    for (auto it = name.begin(); it != name.end(); ++it) {
        score += *it - 'A' + 1;
    }

    return score;
}

int main(int argc, char** argv) {
    std::fstream in("../input/euler_0022.txt");
    
    std::vector<std::string> names;
    std::string str;
    while (!in.eof()) {
        std::getline(in, str, ',');
        names.push_back(str.substr(1, str.length() - 2));
    }

    std::sort(names.begin(), names.end());

    int score = 0;
    for (int i = 1; i <= names.size(); ++i) {
        score += i * get_score(names[i - 1]);
    }

    std::cout << score << std::endl;

    return 0;
}