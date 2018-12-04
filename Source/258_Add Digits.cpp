#include <iostream>
using namespace std;

/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2.
Since 2 has only one digit, return it.
Follow up:
Could you do it without any loop/recursion in O(1) runtime?

258. Add Digits: https://leetcode.com/problems/add-digits/description/
*/

//4ms recursion solution:
int addDigits(int num) {
	return num < 10 ? num : addDigits(num / 10 + num % 10);
}

/*
            / 0              (n == 0)
dr(n) ={   9              (n != 0 && n % 9 == 0)
            \ n % 9       (n % 9 != 0)

equals to 

dr(n) = 1 + (n - 1) % 9

	https://en.wikipedia.org/wiki/Digital_root#Congruence_formula
*/
int addDigits2(int num) {
	return 1 + (num - 1) % 9;
}

int main_258()
{
	int num = 121;
	int res = addDigits(num);
	cout << res << endl;
	system("pause");
	return 0;
}
