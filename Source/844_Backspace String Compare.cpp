#include <iostream>
#include <string>
using namespace std;

/*

Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?

844. Backspace String Compare: https://leetcode.com/problems/backspace-string-compare/description/
*/

//my 4ms solution:
bool backspaceCompare(string S, string T) {
	string s1, s2;
	for (auto i : S)
	{
		if (i != '#')
			s1.push_back(i);
		else if (!s1.empty())
			s1.pop_back();
	}
	for (auto i : T)
	{
		if (i != '#')
			s2.push_back(i);
		else if (!s2.empty())
			s2.pop_back();
	}
	return s1 == s2;
}

//0ms
class Solution {
public:
	static string helper(string S) {
		string s;
		for (int i = 0; i < S.length(); ++i) {
			if (S[i] == '#') {
				if (s.length())
					s.pop_back();
			}
			else {
				s.push_back(S[i]);
			}
		}
		return s;
	}

	static bool backspaceCompare(string S, string T) {
		return helper(S) == helper(T);
	}
};
int main_844()
{
	string S = "y#fo##f";
	string T = "y#f#o##f";
	bool ret = Solution::backspaceCompare(S, T);
	cout << boolalpha << ret << endl;
	system("pause");
	return 0;
}