#include <iostream>

using namespace std;

/*
Given an integer n, return the number of trailing zeroes in n!.

Example 1:

Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Note: Your solution should be in logarithmic time complexity.

172. Factorial Trailing Zeroes: https://leetcode.com/problems/factorial-trailing-zeroes/description/
*/


/*
The idea is:

1.The ZERO comes from 10.
2.The 10 comes from 2 x 5
3.And we need to account for all the products of 5 and 2. likes 4¡Á5 = 20 ...
4.So, if we take all the numbers with 5 as a factor, we'll have way more than enough even numbers to pair with them to get factors of 10
*/
int trailingZeroes(int n) {
	int count = 0;
	for (long long i = 5; n / i; i *= 5)
		count += n / i;
	return count;
}

int trailingZeroes2(int n) {
	int res = 0;
	while (n){
		n /= 5;
		res += n;
	}
	return res;
}

int main_172()
{
	int res = trailingZeroes(13);
	cout << res << endl;
	system("pause");
	return 0;
}
