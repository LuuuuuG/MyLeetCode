#include <iostream>
using namespace std;

/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = -2, b = 3
Output: 1

371. Sum of Two Integers: https://leetcode.com/problems/sum-of-two-integers/description/
*/

int getSum(int a, int b) {
	int sum; //不含进位的和
	int add1; //进位

	while (b != 0)
	{
		sum = a^b;
		add1 = (a&b) << 1;
		a = sum;
		b = add1;
	}
	return a;
}

int main()
{
	int res = getSum(-2, 3);
	cout << res << endl;

	system("pause");
	return 0;
}