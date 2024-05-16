#include "pch.h"
#include "../PrimeFactorsTDD/prime-factors.cpp"

TEST(TestCaseName, TestName) {
	PrimeFactors primeFactors;
	vector<int> factors = primeFactors.of(1);
	ASSERT_EQ(0, factors.size());
}