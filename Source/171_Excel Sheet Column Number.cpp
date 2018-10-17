#include <iostream>
using namespace std;

/*

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...
Example 1:

Input: "A"  [1]*26^(0)
Output: 1
Example 2:

Input: "AB" [1]*26^(1) + [2] * 26^(0)
Output: 28
Example 3:

Input: "ZY" [26] *26^(1) +[25] * 26^ (0)
Output: 701

171. Excel Sheet Column Number: https://leetcode.com/problems/excel-sheet-column-number/description/
*/

int titleToNumber(string s) {
	int sum = 0;
	int cnt = s.size();
	for (auto i : s)
	{
		sum +=  (i - 'A' + 1)* pow(26, --cnt);
	}
	return sum;
}

int titleToNumber2(string s) {
	int res = 0;
	for (int i = 0; i < s.length(); ++i) {
		res = res * 26 + s[i] - 'A' + 1;
	}
	return res;
}

int main_171()
{
	int res = titleToNumber("AAA");
	cout << res << endl;
	system("pause");
	return 0;
}