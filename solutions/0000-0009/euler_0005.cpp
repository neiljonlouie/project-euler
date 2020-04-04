#include <iostream>
#include "../util.h"

int main(int argc, char** argv) {
	int max = 20;

	std::vector<int> primes;
	generate_primes(primes, max);
	
	int* needed = (int*)calloc(primes.size(), sizeof(int));
	int temp = 0, ctr = 0, idx = 0;
	for (int i = 2; i <= max; i++) {
		idx = 0;
		temp = i;
		ctr = 0;
		while (temp > 1) {
			if (temp % primes[idx] == 0) {
				temp /= primes[idx];
				ctr++;

				if (ctr > needed[idx]) {
					needed[idx] = ctr;
				}
			} else {
				ctr = 0;
				idx++;
			}
		}
	}

	int result = 1;
	for (int i = 0; i < primes.size(); i++) {
		for (int j = 0; j < needed[i]; j++) {
			result *= primes[i];
		}
	}

	std::cout << result << std::endl;
	std::free(needed);
	return 0;
}