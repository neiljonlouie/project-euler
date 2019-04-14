#include <cstdlib>
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
	long long target = 600851475143L;
	long long root_long = 0;

	while (root_long * root_long < target) root_long++;
	int root = static_cast<int>(root_long);

	std::vector<int> primes;
	bool* is_composite = (bool *)calloc(root, sizeof(bool));
	for (int i = 2; i < root; i++) {
		if (is_composite[i]) continue;

		for (int j = 2 * i; j < root; j += i) is_composite[j] = true;
		primes.push_back(i);
	}

	for (std::vector<int>::const_iterator it = primes.end() - 1; it >= primes.begin(); it--) {
		if (target % *it == 0) {
			std::cout << *it << std::endl;
			break;
		}
	}

	std::free(is_composite);
	return 0;
}