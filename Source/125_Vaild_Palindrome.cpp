#include <iostream>
#include <string>
using namespace std;
/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false

125. Valid Palindrome: https://leetcode.com/problems/valid-palindrome/description/
*/

bool isPalindrome(string s)
{
		int start = 0, end = s.length() - 1;
		while (start<end) {
			if (!isalnum(s[start])) 
				start++;
			else if (!isalnum(s[end])) 
				end--;
			else {
				if (tolower(s[start++]) != tolower(s[end--])) 
					return false;
			}
		}
		return true;
}


int main_125()
{
	string s = "A man, a plan, a canal: Panama";
	bool res = isPalindrome(s);
	cout << "res = " << boolalpha << res << endl;

	system("pause");
	return 0;
}