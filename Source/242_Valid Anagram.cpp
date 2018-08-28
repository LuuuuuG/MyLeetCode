#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

242. Valid Anagram: https://leetcode.com/problems/valid-anagram/description/
*/

//using sort. 24ms
bool isAnagram(string s, string t) {
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	return s == t;
}

//12ms
bool isAnagram2(string s, string t) {
	vector<int> a(26, 0);
	for (auto c : s){
		a[c - 'a']++;
	}
	for (auto c : t){
		a[c - 'a']--;
	}
	for (auto c : a){
		if (c) return false;
	}
	return true;
}

int main_242()
{

	string s = "anagram";
	string t = "nagaram";
	bool b = isAnagram2(s, t);
	cout << boolalpha << b << endl;

	system("pause");
	return 0;
}