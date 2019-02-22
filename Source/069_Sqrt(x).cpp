#include <iostream>
#include <algorithm>
using namespace std;

/*
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since
the decimal part is truncated, 2 is returned.

69. Sqrt(x): https://leetcode.com/problems/sqrtx/description/
*/

//Newton's method
int mySqrt(int x) {
	long r = x;
	while (r*r > x)
		r = (r + x / r) / 2;
	return r;
}

int main_69()
{
	int test = 8;
	int res = mySqrt(test);

	cout << res << endl;

	system("pause");
	return 0;
}