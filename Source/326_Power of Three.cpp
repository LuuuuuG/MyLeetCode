#include <iostream>
using namespace std;

/*
Given an integer, write a function to determine if it is a power of three.

Example 1:

Input: 27
Output: true
Example 2:

Input: 0
Output: false
Example 3:

Input: 9
Output: true
Example 4:

Input: 45
Output: false
Follow up:
Could you do it without using any loop / recursion?

326. Power of Three: https://leetcode.com/problems/power-of-three/description/
*/

//56ms solution.
bool isPowerOfThree(int n) {
	if (n > 1){
		while (n % 3 == 0)
		{
			n /= 3;
		}
	}
	return n == 1;
}

int main_326()
{
	bool ret = isPowerOfThree(45);
	cout << boolalpha << ret << endl;
	system("pause");
	return 0;
}