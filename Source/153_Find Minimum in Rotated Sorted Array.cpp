#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2]
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0


153. Find Minimum in Rotated Sorted Array: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
*/

int findMin(vector<int>& num) {
	int start = 0, end = num.size() - 1;

	while (start < end) {
		if (num[start] < num[end])
			return num[start];

		int mid = (start + end) / 2;

		if (num[mid] >= num[start]) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
	}

	return num[start];
}

int findMin2(vector<int>& nums) {
	int start = 0, end = nums.size() - 1;
	while (nums[start] > nums[end]) {
		int mid = ceil((start + end) / 2);
		if (nums[start] < nums[mid]) {
			start = mid;
		}
		else if (nums[end] > nums[mid]) {
			end = mid;
		}
		else {
			return nums[end];
		}
	}
	//cout<<nums[start]<<","<<nums[end]<<endl;
	return nums[start] > nums[end] ? nums[end] : nums[start];
}