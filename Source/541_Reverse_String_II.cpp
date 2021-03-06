#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. 
If there are less than k characters left, reverse all of them. 
If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.

Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"

Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]

541. Reverse String II:  https://leetcode.com/problems/reverse-string-ii/description/
*/

/**
* 0            k           2k          3k
* |-----------|-----------|-----------|---
* +--reverse--+           +--reverse--+
*/
string reverseStr(string s, int k) {
	for (int left = 0; left < s.size(); left += 2 * k) {
		for (int i = left, j = min(left + k - 1, (int)s.size() - 1); i < j; i++, j--) {
			swap(s[i], s[j]);
		}
	}
	return s;
}

// one line c++
string reverseStr2(string s, int k) {
	for (int i = 0; i < s.size(); i += 2 * k) 
		reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
	return s;
}

int main_541()
{
	string s = "abcdefghij";
	int k = 2;
	//reverse(s.rbegin(), s.rend());
	//cout << "s = " << s << endl;
	//string tmp( s.rbegin(), s.rend() );
	//cout << "tmp = " << tmp << endl;
	string res = reverseStr2(s, k);
	cout << "res = " << res << endl;

	system("pause");
	return 0;
}