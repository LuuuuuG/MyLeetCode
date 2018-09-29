#include <iostream>
#include <string>
using namespace std;

/*

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

67. Add Binary: https://leetcode.com/problems/add-binary/description/
*/

string addBinary(string a, string b) {
	string res;
	int c = 0, i = a.size() - 1, j = b.size() - 1;
	while (i >= 0 || j >= 0 || c == 1)
	{
		c += i >= 0 ? a[i--] - '0' : 0;
		c += j >= 0 ? a[j--] - '0' : 0;
		res = to_string(c % 2) + res;
		c /= 2;
	}
	return res;
}

int main_67()
{
	string a = "11";
	string b = "1";
	string res = addBinary(a, b);
	cout << res << endl;
	system("pause");
	return 0;
}