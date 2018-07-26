#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
/*---------------------------------------------------------------------------------------------
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.

14. Longest Common Prefix: https://leetcode.com/problems/longest-common-prefix/description/
---------------------------------------------------------------------------------------------------------*/

string longestCommonPrefix(vector<string>& strs) {
	if (strs.empty())
		return "";
	string res = strs[0];
	for (int i = 0; i < strs.size(); ++i)
		for (int j = 0; j < res.size(); ++j)
			if (strs[i][j] != res[j])
			{
				res.resize(j);
				break;
			}
	return res;
}

string longestCommonPrefix2(vector<string>& strs) {
	string prefix = "";
	for (int idx = 0; strs.size()>0; prefix += strs[0][idx], idx++)
	for (int i = 0; i<strs.size(); i++)
	if (idx >= strs[i].size() || (i > 0 && strs[i][idx] != strs[i - 1][idx]))
		return prefix;
	return prefix;
}

int main_14()
{
	vector<string> vs = { "Hello", "Hey", "Her" };
	string res = longestCommonPrefix(vs);
	cout << " longestCommonPrefix is : " << res << endl;

	system("pause");
	return 0;
}