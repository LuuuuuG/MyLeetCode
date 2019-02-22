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
	sort(nums.begin(), nums.end());
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
/*
1) everytime check if targe == nums[mid], if so, we find it.

2) otherwise, we check if the first half is in order (i.e. nums[left]<=nums[mid])
  and if so, go to step 3), otherwise, the second half is in order,   go to step 4)

3) check if target in the range of [left, mid-1] (i.e. nums[left]<=target < nums[mid]), 
if so, do search in the first half, i.e. right = mid-1; otherwise, search in the second half left = mid+1;

4)  check if target in the range of [mid+1, right] (i.e. nums[mid]<target <= nums[right]), 
if so, do search in the second half, i.e. left = mid+1; otherwise search in the first half right = mid-1;
*/
bool search2(vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1, mid;

	while (left <= right)
	{
		mid = (left + right) >> 1;
		if (nums[mid] == target) return true;

		// the only difference from the first one, trickly case, just updat left and right
		if ((nums[left] == nums[mid]) && (nums[right] == nums[mid])) { ++left; --right; }
		

		else if (nums[left] <= nums[mid])
		{
			if ((nums[left] <= target) && (nums[mid] > target)) right = mid - 1;
			else left = mid + 1;
		}
		else
		{
			if ((nums[mid] < target) && (nums[right] >= target)) left = mid + 1;
			else right = mid - 1;
		}
	}
	return false;

}
int main_81()
{
	vector<int> v{ 1,3,1,1 };
	bool res = search(v, 3);
	cout << boolalpha <<  res << endl;
	system("pause");
	return 0;
}