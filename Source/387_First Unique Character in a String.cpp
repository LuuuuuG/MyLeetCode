#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.

387. First Unique Character in a String: https://leetcode.com/problems/first-unique-character-in-a-string/description/
*/

//map solution.
int firstUniqChar(string s) {
	unordered_map<char, int> m;
	for (auto i : s)
	{
		m[i]++;
	}
	for (int i = 0; i < s.size(); ++i)
	{
		if (m[s[i]] == 1)
			return i;
	}
	return -1;
}

//array solution.
int firstUniqChar2(string s) {
	int list[256] = { 0 };
	for (auto i : s)
		list[i] ++;
	for (int i = 0; i < s.length(); i++){
		if (list[s[i]] == 1) return i;
	}
	return -1;
}

int main_387()
{
	int pos = firstUniqChar("loveleetcode");
	cout << pos << endl;
	system("pause");
	return 0;
}