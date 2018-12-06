#include <iostream>
using namespace std;

/*

Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true
Explanation: 20 = 1
Example 2:

Input: 16
Output: true
Explanation: 24 = 16
Example 3:

Input: 218
Output: false

231. Power of Two: https://leetcode.com/problems/power-of-two/description/
*/

bool isPowerOfTwo(int n) {
	if (n == 0) return false;
	return (n & (n - 1)) == 0;
}

bool isPowerOfTwo2(int n) {
	return n > 0 && (n & n - 1) == 0;
}

int main_231()
{
	int n = 218;
	bool res = isPowerOfTwo(n);
	cout << boolalpha << res << endl;

	system("pause");
	return 0;
}