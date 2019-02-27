#include <iostream>
#include <unordered_map>
using namespace std;

/*

Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

383. Ransom Note: https://leetcode.com/problems/ransom-note/
*/

bool canConstruct(string ransomNote, string magazine) {
	unordered_map<char,int> map;
	for(auto m : magazine)
		++map[m];
	for(auto r : ransomNote)
	{
		if(--map[r] < 0)
			return false;
	}
	return true;
}