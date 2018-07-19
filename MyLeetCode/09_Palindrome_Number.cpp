#include <iostream>
#include <time.h>

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

int main()
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