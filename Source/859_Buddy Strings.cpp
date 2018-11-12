#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

/*

Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.



Example 1:

Input: A = "ab", B = "ba"
Output: true
Example 2:

Input: A = "ab", B = "ab"
Output: false
Example 3:

Input: A = "aa", B = "aa"
Output: true
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false


Note:

0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist only of lowercase letters.

859. Buddy Strings: https://leetcode.com/problems/buddy-strings/description/
*/

bool buddyStrings(string A, string B) {
	if (A.size() != B.size())
		return false;
	// Repeat: same string, A needs repeated char, like "aab" "aab"
	if (A == B && set<char>(A.begin(), A.end()).size() < A.size()) return true;

	// Swap: There should be only two to change
	vector<int> dif;
	for (int i = 0; i < A.length(); ++i)
	{
		if (A[i] != B[i]) 
			dif.push_back(i);
		if (dif.size() > 2)
			return false;
	}
	return dif.size() == 2 && A[dif[0]] == B[dif[1]] && A[dif[1]] == B[dif[0]];
}

int main_859()
{
	string A = "aaaaaaabc", B = "aaaaaaacb";
	bool ret = buddyStrings(A, B);
	cout << boolalpha << ret << endl;
	system("pause");
	return 0;
}