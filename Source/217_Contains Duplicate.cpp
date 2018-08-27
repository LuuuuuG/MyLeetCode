#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

/*
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
217. Contains Duplicate: https://leetcode.com/problems/contains-duplicate/description/
*/

//Time Limit Exceeded
bool containsDuplicate(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = i + 1; j < nums.size(); ++j)
		{
			if (nums[i] == nums[j])
				return true;
		}
	}
	return false;
}

// using sort 20ms.
bool containsDuplicate2(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	for (int i = 0; i<int(nums.size()) - 1; i++) {
		if (nums[i] == nums[i + 1])
			return true;
	}
	return false;
}

//set 24ms
bool containsDuplicate3(vector<int>& nums) {
	set<int> first(nums.begin(), nums.end());
	int res = first.size();
	multiset<int> second(nums.begin(), nums.end());
	res = second.size();
	unordered_set<int> third(nums.begin(), nums.end());
	res = third.size();
	unordered_multiset<int> four(nums.begin(), nums.end());
	res = four.size();
	return first.size() < nums.size();
	//return set<int>(nums.begin(), nums.end()).size() < nums.size();
}
//set 36ms
bool containsDuplicate4(vector<int>& nums) {
	set<int> mySet;
	// unordered_set<int> mySet;
	// multiset<int> mySet;
	// unordered_multiset<int> mySet;
	for (auto& num : nums) {
		if (mySet.find(num) != mySet.end())
			return true;
		mySet.insert(num);
	}
	return false;
}

int main_217()
{
	vector<int > v = { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };
	bool b = containsDuplicate4(v);
	cout << boolalpha << b << endl;
	for (auto it : v)
		cout << it << " ";
	cout << endl;
	system("pause");
	return 0;
}