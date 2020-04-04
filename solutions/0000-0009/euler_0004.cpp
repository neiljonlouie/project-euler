#include <iostream>

bool is_palindrome(int num) {
	int temp = num, reverse = 0;
	while (temp > 0) {
		reverse *= 10;
		reverse += (temp % 10);
		temp /= 10;
	}

	return reverse == num;
}

int main(int argc, char** argv) {
	int max_pal = 0, curr = 0;
	for (int i = 100; i <= 999; i++) {
		for (int j = i; j <= 999; j++) {
			curr = i * j;
			if (is_palindrome(curr) && curr > max_pal) {
				max_pal = curr;
			}
		}
	}

	std::cout << max_pal << std::endl;
	return 0;
}