#include <iostream>
using namespace std;

/*

Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer¡¯s binary representation.

Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.


476. Number Complement: https://leetcode.com/problems/number-complement/description/
*/

int findComplement(int num) {
	int res = 0;
	int cnt = 0;
	while (num)
	{
		if (num % 2 == 0)
			res += pow(2, cnt);
		num /= 2;
		cnt++;
	}
	return res;
}

int main_476()
{
	int num = 5;
	int res = findComplement(num);
	cout << res << endl;
	system("pause");
	return 0;
}