#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1

41. First Missing Positive: https://leetcode.com/problems/first-missing-positive/description/
*/

int firstMissingPositive(vector<int>& nums) {
	int n = nums.size();
	for (int i = 0; i < n; i++)
	{
		while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
			swap(nums[i], nums[nums[i] - 1]);
	}
	for (int i = 0; i < n; i++)
	{
		if (nums[i] != i + 1)
			return i + 1;
	}
	return n + 1;
}

int firstMissingPositive2(vector<int>& nums) {
	unordered_map<int, int> map;
	int z = INT_MIN;
	for (int i = 0; i < nums.size(); ++i) {
		map[nums[i]]++;
		z = max(z, nums[i]);
	}

	for (int i = 1; i <= z; ++i) {
		if (map.count(i) > 0) {
			continue;
		}
		else {
			return i;
		}
	}
	if (z > 0) {
		return z + 1;
	}
	else {
		return 1;
	}

}

int main_41()
{
	vector<int> v{ 3,4,-1, 1 };
	int res = firstMissingPositive(v);
	cout << res << endl;

	system("pause");
	return 0;
}