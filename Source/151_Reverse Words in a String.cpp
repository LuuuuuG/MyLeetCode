#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
Given an input string, reverse the string word by word.



Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.


Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.


151. Reverse Words in a String: https://leetcode.com/problems/reverse-words-in-a-string/
*/
namespace {
	string reverseWords(string s) {

		reverse(s.begin(), s.end());//reverse whole words.
		int i = 0, j = 0;
		while (i < s.size())
		{
			while (i < s.size() && s[i] == ' ')
				++i;//i is the start of the word
			if (i < s.size() && j > 0)
				s[j++] = ' ';
			int start = j;
			while (i < s.size() && s[i] != ' ')
				s[j++] = s[i++];
			reverse(s.begin() + start, s.begin() + j);//reverse single word.
		}
		s.resize(j);//clean extra chars.
		return s;
	}
}
int main_151()
{
	string s = "hello world!";
	
	string res = reverseWords(s);
	cout << res << endl;

	system("pause");
	return 0;
}