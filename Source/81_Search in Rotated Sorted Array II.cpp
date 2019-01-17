#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?

81. Search in Rotated Sorted Array II: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
*/

bool search(vector<int>& nums, int target) {

	int start = 0, end = nums.size();
	while (start < end)
	{
		int mid = start + (end - start) / 2;
		int num = 0;
		if ((nums[mid] < nums[0]) == (target < nums[0]))
			num = nums[mid];
		else
			num = target < nums[0] ? INT_MIN : INT_MAX;

		if (num < target)
			start = mid + 1;
		else if (num > target)
			end = mid;
		else
			return true;
	}
	return false;
}

int main_NG()
{
	vector<int> v{ 1,3,1,1 };
	int res = search(v, 0);
	cout << res << endl;
	system("pause");
	return 0;
}