#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
	std::ifstream in("../files/euler_0008.txt");
	std::string str;
	in >> str;

	int max_idx = str.length();
	int len = 13;

	long long int max = 1, curr = 0;
	for (int i = 0; i < max_idx; i++) {
		if (str[i] == '0') {
			curr = 0;
			continue;
		}

		if (curr == 0) {
			int ctr = 0;
			curr = 1;
			while (ctr < len && i < 1000) {
				curr *= (str[i] - '0');
				ctr++;
				i++;

				if (str[i] == '0') {
					curr = 0;
					break;
				}
			}

			i--;
		} else {
			curr /= (str[i - len] - '0');
			curr *= (str[i] - '0');
		}

		if (curr > max) {
			max = curr;
		}
	}

	std::cout << max << std::endl;
	return 0;
}