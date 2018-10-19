#include <iostream>
#include <cstdint>
#include <algorithm>
using namespace std;

/*

Reverse bits of a given 32 bits unsigned integer.

Example:

Input: 43261596
Output: 964176192
Explanation: 43261596 represented in binary as 00000010100101000001111010011100,
return 964176192 represented in binary as 00111001011110000010100101000000.
Follow up:
If this function is called many times, how would you optimize it?

190. Reverse Bits: https://leetcode.com/problems/reverse-bits/description/
*/

uint32_t reverseBits(uint32_t n) {
	uint32_t res = 0;
	int pos = 32;
	while (n)
	{
		res += n % 2 * pow(2, --pos);
		n /= 2;
	}
	return res;
}

int main_190()
{
	uint32_t res = reverseBits(43261596);
	cout << res << endl;
	system("pause");
	return 0;
}
