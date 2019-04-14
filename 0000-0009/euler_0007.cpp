#include <iostream>
#include <vector>
#include "../util.h"

int main(int argc, char** argv) {
	std::vector<int> primes;
	int max = 1000000;
	generate_primes(primes, max);
	std::cout << "max = " << max << std::endl;
	std::cout << "primes.size() = " << primes.size() << std::endl;
	if (primes.size() >= 10000) {
		std::cout << "primes[10000] = " << primes[10000] << std::endl;
	}

	return 0;
}
