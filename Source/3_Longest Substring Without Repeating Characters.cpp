#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

3. Longest Substring Without Repeating Characters: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/


*/

//int lengthOfLongestSubstring(string s) {
//	string msxSub, tmp;
//	for (int i = 0, j = i + 1; j < s.size(); ++j)
//	{
//		if (s[j] != s[j - 1])
//		{
//			string tmp(s, i, j - i);
//			if (tmp.size() > msxSub.size())
//				msxSub = tmp;
//		}
//		else
//			i = j;
//	}
//	return msxSub.size();
//}

int lengthOfLongestSubstring(string s) {
	vector<int> dict(256, -1);
	int maxLen = 0, start = -1;
	for (int i = 0; i != s.length(); i++) {
		if (dict[s[i]] > start)
			start = dict[s[i]];
		dict[s[i]] = i;
		maxLen = max(maxLen, i - start);
	}
	return maxLen;
}

int main_3()
{
	string s = "abcabcab";
	int res = lengthOfLongestSubstring(s);
	cout << res << endl;
	system("pause");
	return 0;
}