#include <iostream>
#include <vector>
using namespace std;

class PrimeFactors {
public:
	vector<int> of(int number) {
		vector<int> factors;
		for (int candidate = 2; number > 1; candidate++) {
			for (; number % candidate == 0; number /= candidate) {
				factors.push_back(candidate);
			}
		}
		return factors;
	}
};