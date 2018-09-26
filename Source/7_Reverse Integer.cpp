#include <iostream>
using namespace std;

/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: 
[−2^31,  2^31 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

7. Reverse Integer: https://leetcode.com/problems/reverse-integer/description/
*/

int reverse(int x)
{
	int res = 0;
	while (x)
	{
		res = res * 10 + x % 10;
		x /= 10;
	}
	//return res;
	return (res>INT_MAX || res < INT_MIN) ? 0 : res;
}

int main_07(){
	int x = -123;
	int res = reverse(x);
	cout << res << endl;
	system("pause");
	return 0;
}