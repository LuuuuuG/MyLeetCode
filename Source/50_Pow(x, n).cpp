#include <iostream>
using namespace std;

/*

Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]

50. Pow(x, n) : https://leetcode.com/problems/powx-n/description/
*/

//Time Limit Exceeded...
double myPow(double x, int n) {
	double res = 1.0;
	if (x == 0.0)
		return x;
	if (n < 0)
	{
		x = 1 / x;
		n = 0 - n;
	}
	while (n > 0)
	{
		res *= x;
		--n;
	}
	return res;
}

//iterative
double myPow2(double x, int n) {
	if (n == 0) return 1;
	if (n<0){
		n = -n;
		x = 1 / x;
	}
	return n % 2 == 0 ? myPow(x*x, n / 2) : x*myPow(x*x, n / 2);
}
//avoid integer overflow
double myPow3(double x, int n) {

	if (n == 0)
		return 1;
	if (n < 0){
		return 1 / x * myPow(1 / x, -(n + 1));
	}
	return (n % 2 == 0) ? myPow(x*x, n / 2) : x*myPow(x*x, n / 2);
}
int main_50()
{
	double res = myPow2();
	cout << res << endl;
	system("pause");
	return 0;
}