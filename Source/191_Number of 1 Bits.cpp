#include <iostream>
#include <cstdint>
using namespace std;

/*

Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Example 1:
Input: 11
Output: 3
Explanation: Integer 11 has binary representation 00000000000000000000000000001011

Example 2:
Input: 128
Output: 1
Explanation: Integer 128 has binary representation 00000000000000000000000010000000

191. Number of 1 Bits: https://leetcode.com/problems/number-of-1-bits/description/
*/

int hammingWeight(uint32_t n) {
	int cnt = 0;
	while (n)
	{
		if (n % 2)
			++cnt;
		n /= 2;
	}
	return cnt;
}

//C++ Solution: n & (n - 1)
int hammingWeight2(uint32_t n) {
	int count = 0;

	while (n) {
		n &= (n - 1);
		count++;
	}

	return count;
}

int main_191()
{
	int res = hammingWeight2(11);
	cout << res << endl;
	system("pause");
	return 0;
}