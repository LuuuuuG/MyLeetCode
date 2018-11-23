#include <iostream>
#include <string>
using namespace std;
 
/*

X is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is different from X.  Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.

Now given a positive number N, how many numbers X from 1 to N are good?

Example:
Input: 10
Output: 4
Explanation:
There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.

788. Rotated Digits: https://leetcode.com/problems/rotated-digits/description/
*/

/*
contain 3, 4 ,7 is not good
contain 2 5 6 9 is good
0 1 8 unchanged after rotating.
*/

bool isGood(string num)
{
	bool flag = false;
	for (auto i : num)
	{
		if (i == '2' || i == '5' || i == '6' || i == '9')
			flag = true;
		if (i == '3' || i == '4' || i == '7')
			return false;
	}
	return flag;
}

int rotatedDigits(int N)
{
	int res = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (isGood(to_string(i)))
			++res;
	}
	return res;
}

//iteration 0 ms
class Solution {
public:

	bool isGood(int n, bool flag){
		if (n == 0)
			return flag;

		int d = n % 10;
		if (d == 3 || d == 4 || d == 7)
			return false;

		if (d == 0 || d == 1 || d == 8)
			return isGood(n / 10, flag);

		return isGood(n / 10, true);
	}

	int rotatedDigits(int N) {
		int res = 0;

		for (int i = 1; i <= N; i++){
			if (isGood(i, false))
				res++;
		}

		return res;
	}
};

int main_788()
{
	int N = 10;
	int res = rotatedDigits(N);
	cout << res << endl;
	system("pause");
	return 0;
}