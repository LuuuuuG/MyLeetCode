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
	int len = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] != ' ')
			len++;
		else if (s[i + 1] && s[i + 1] != ' ')
			len = 0;
	}
	return len;
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

int lengthOfLastWord3(string s)
{
	int len = 0, endIndx = s.length() - 1;
	for (int i = endIndx; i >= 0; --i)
	{
		if (s[i] == ' ')
		{
			if (len > 0) return len;
		}
		else
			++len;
	}
	return len;
}
void test()
{
	char* s = "Hello world";
	while (*s)
	{
		printf("*s++ = %c\n", *s++); //H
		printf("*s = %c\n", *s);	// e
		printf("*(s++) = %c\n", *(s++));	//e
		printf("*s = %c\n", *s);	//l
	}

}
int main_58()
{
	string s = "Hello world";
	int res = lengthOfLastWord(s);
	//int res = lengthOfLastWord3(s);
	cout << "res = " << res << endl;
	//test();
	char *c = "Hello world";
	int res2 = lengthOfLastWord2(c);
	cout << "res2 = " << res2 << endl;

	system("pause");
	return 0;
}