#include <iostream>
using namespace std;

/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5

58. Length of Last Word: https://leetcode.com/problems/length-of-last-word/description/
*/
#include <cstdio>
int lengthOfLastWord(string s)
{
	int pos = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i]== ' ')
			pos = i + 1;
	}
	return s.size() - pos;
}


int lengthOfLastWord2(const char* s) {
	int len = 0;
	while (*s) {
		if (*s++ != ' ')
			++len;
		else if (*s && *s != ' ')
			len = 0;

	}
	return len;
}
int main()
{
	string s = "Hi ";
	int res = lengthOfLastWord(s);
	cout << "res = " << res << endl;

	char *c = "Hello world";
	int res2 = lengthOfLastWord2(c);
	cout << "res2 = " << res2 << endl;

	system("pause");
	return 0;
}