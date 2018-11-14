#include <iostream>
#include <string>
using namespace std;

/*
Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.



Example 1:

Input: "ab-cd"
Output: "dc-ba"
Example 2:

Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"


Note:

S.length <= 100
33 <= S[i].ASCIIcode <= 122
S doesn't contain \ or "

917. Reverse Only Letters: https://leetcode.com/problems/reverse-only-letters/description/ 
*/

string reverseOnlyLetters(string S) {
	int i = 0;
	int j = S.size() - 1;
	while (i < j)
	{
		if (!isalpha(S[i]))
			++i;
		if (!isalpha(S[j]))
			--j;
		if (isalpha(S[i]) && isalpha(S[j]))
		{
			swap(S[i], S[j]);
			++i;
			--j;
		}
	}
	return S;
}

string reverseOnlyLetters2(string S) {
	for (int i = 0, j = S.length() - 1; i < j; ++i, --j) {
		while (i < j && !isalpha(S[i])) ++i;
		while (i < j && !isalpha(S[j])) --j;
		swap(S[i], S[j]);
	}
	return S;
}

int main_917()
{
	string s = "Test1ng-Leet=code-Q!";
	string res = reverseOnlyLetters(s);
	cout << res << endl;
	system("pause");
	return 0;
}