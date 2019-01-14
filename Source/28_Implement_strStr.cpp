#include <iostream>
#include <string>
using namespace std;

/*
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1

https://leetcode.com/problems/implement-strstr/description/

C++ Brute-Force and KMP: https://leetcode.com/problems/implement-strstr/discuss/12956/C++-Brute-Force-and-KMP

*/

//Brute-Force
int strStr(string haystack, string needle) {
	int sLen = haystack.size();
	int pLen = needle.size();
	for (int i = 0; i <= sLen - pLen; ++i)
	{
		int j = 0;
		for (; j < pLen;++j)
			if (haystack[i + j] != needle[j])
				break;
		if (j == pLen)
			return i;

	}
	return -1;
}

//elegant solution:
int strStr(string haystack, string needle) {
	for (int i = 0;; ++i)	{
		for (int j = 0;; ++j)	{
			if (j == needle.size()) return i;
			if (i + j == haystack.size()) return -1;
			if (haystack[i + j] != needle[j]) break;
		}
	}
}

int main_028()
{
	string s = "Hi world";
	string p = "";
	int res = strStr(s, p);
	cout << "res = " << res << endl;
	
	system("pause");
	return 0;
}