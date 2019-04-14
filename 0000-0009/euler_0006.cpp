#include <iostream>

int main(int argc, char** argv) {
	int sum_of_squares = 0, sum = 0, square_of_sum = 0;
	int max = 100;
	for (int i = 1; i <= max; i++) {
		sum_of_squares += i * i;
		sum += i;
	}

	square_of_sum = sum * sum;

	std::cout << square_of_sum - sum_of_squares << std::endl;

	return 0;
}