#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false

219. Contains Duplicate II: https://leetcode.com/problems/contains-duplicate-ii/description/
*/

// my 1344 ms solution. Q_Q
bool containsNearbyDuplicate(vector<int>& nums, int k) {
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = i + 1; j < nums.size(); ++j)
			{
				if ((nums[i] == nums[j]) && (j - i <= k))
					return true;
			}
		}
		return false;
}

bool containsNearbyDuplicate2(vector<int>& nums, int k)
{
	unordered_set<int> s;

	if (k <= 0) return false;
	if (k >= nums.size()) k = nums.size() - 1;

	for (int i = 0; i < nums.size(); i++)
	{
		if (i > k) s.erase(nums[i - k - 1]);
		if (s.find(nums[i]) != s.end()) return true;
		//if (s.count(nums[i])) return true;
		//if (!s.insert(nums[i]).second) return true;
		s.insert(nums[i]);
	}
	return false;
}

int main_219()
{
	vector<int> v = { 1, 2, 3, 1, 2, 3 };
	bool b = containsNearbyDuplicate(v, 3);
	cout << boolalpha << b << endl;
	system("pause");
	return 0;
}