#include <iostream>

int main(int argc, char** argv) {
	int prev_1 = 0, prev_2 = 1, curr = 0, sum = 0;
	while (curr < 4000000) {
		curr = prev_1 + prev_2;
		if (curr % 2 == 0) sum += curr;

		prev_1 = prev_2;
		prev_2 = curr;
	}

	std::cout << "sum = " << sum << std::endl;

	return 0;
}