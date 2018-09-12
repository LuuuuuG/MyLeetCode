#include <iostream>
#include <string>
using namespace std;

/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"
Note:
The vowels does not include the letter "y".

345. Reverse Vowels of a String: https://leetcode.com/problems/reverse-vowels-of-a-string/description/
*/

string reverseVowels(string s) {
	string vowels = "aeiouAEIOU";
	int i = 0, j = s.size() - 1;
	while (i < j)
	{
		while (vowels.find(s[i]) == string::npos && i < j) ++i;
		while (vowels.find(s[j]) == string::npos && i < j) --j;
		swap(s[i++], s[j--]);
	}
	return s;
}

int main_345()
{
	string s = "hhll";
	string res = reverseVowels(s);
	cout << "res = " << res << endl;
	system("pause");
	return 0;
}