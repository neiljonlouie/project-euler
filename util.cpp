#include "util.h"

#include <cstdlib>

void generate_primes(std::vector<int>& primes, int max) {
	bool* is_composite = (bool*)calloc(max + 1, sizeof(bool));
	for (int i = 2; i <= max; i++) {
		if (is_composite[i]) continue;

		for (int j = 2 * i; j <= max; j += i) is_composite[j] = true;
		primes.push_back(i);
	}

	std::free(is_composite);
}

