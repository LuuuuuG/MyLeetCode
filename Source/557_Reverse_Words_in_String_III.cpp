#include <iostream>
#include <string>
using namespace std;
/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.

557. Reverse Words in a String III: https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
*/

// my 20 ms soultion >_<
string reverseWords(string s) {
		string res ,tmp;
		for (int i = s.size() - 1; i >= 0; --i)
		{
			if (s[i] != ' ' ){
				tmp += s[i];
			}
			else{
				res =" " + tmp + res; 
				tmp.clear();
			}
		}
		res = tmp + res;
		return res;
}

string reverseWords2(string s) {
	int front = 0;
	for (int i = 0; i <= s.size(); ++i)
	{
		if (i == s.size() || s[i] == ' ')
		{
			cout << "&s[front]: " << &s[front] << " &s[i]: " << &s[i] << endl;
			//cout << front << " " << i << endl;
			reverse(&s[front], &s[i]);
			//reverse(s.begin() + front, s.begin() + i);
			front = i + 1;
		}
	}
	return s;
}

int main_557()
{
	string test = "Let's take LeetCode contest";
	string res = reverseWords2(test);
	//cout << test << endl << res << endl;

	system("pause");
	return 0;
}