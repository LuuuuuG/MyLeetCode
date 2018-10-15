#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output ¡°Fizz¡± instead of the number and for the multiples of five output ¡°Buzz¡±. For numbers which are multiples of both three and five output ¡°FizzBuzz¡±.

Example:

n = 15,

Return:
[
"1",
"2",
"Fizz",
"4",
"Buzz",
"Fizz",
"7",
"8",
"Fizz",
"Buzz",
"11",
"Fizz",
"13",
"14",
"FizzBuzz"
]

412. Fizz Buzz: https://leetcode.com/problems/fizz-buzz/description/
*/

vector<string> fizzBuzz(int n) {
	vector<string> ret;
	for (int i = 1; i <= n; ++i)
	{
		if ((i % 3 == 0) && (i % 5 == 0))
		{
			ret.push_back("FizzBuzz");
		}
		else if (i % 3 == 0)
		{
			ret.push_back("Fizz");
		}
		else if (i % 5 == 0)
		{
			ret.push_back("Buzz");
		}
		else
		{
			ret.push_back(std::to_string(i));
		}
	}
	return ret;
}

int main_412()
{
	vector<string> ret = fizzBuzz(10);

	for (auto i : ret)
		cout << i << endl;

	system("pause");
	return 0;
}
