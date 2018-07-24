#include <iostream>
#include <time.h>

/*
Example 1:
Input: 121
Output: true
*/

/*
Example 2:
Input : -121
Output : false
Explanation : From left to right, it reads - 121. From right to left, it becomes 121 - .Therefore it is not a palindrome
*/

/*
Example 3:
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

bool isPalindrome(int x)
{
	if (x < 0 || (x!=0 && (x % 10) == 0))
		return false;
	int res = 0;
	int tmp = x;
	while (tmp)
	{
		res = res * 10 + tmp % 10;
		tmp /= 10;
	}
	return (res == x);
}

int main_09()
{
	int val = 121;
	clock_t startTime, endTime;
	startTime = clock();
	bool res = isPalindrome(1234321);
	endTime = clock();
	std::cout << "Is Palindrome? " << std::boolalpha << res << std::endl;
	std::cout << "Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << std::endl;

	getchar();
	return 0;
}