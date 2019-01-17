#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

33. Search in Rotated Sorted Array: https://leetcode.com/problems/search-in-rotated-sorted-array/description/
*/

/*
1. �ж� nums [ mid ] �� target ��ͬһ�Σ�
[ 4 5 6 7 1 2 3]����� target = 5����ʱ���鿴�� [ 4 5 6 7 inf inf inf ]��
nums [ mid ] = 7��target > nums [ 0 ]��nums [ mid ] > nums [ 0 ]������������ͬһ�� nums [ mid ] = 7�����ñ仯��

2.�ж� nums [ mid ] �� target ����ͬһ�Σ�
[ 4 5 6 7 1 2 3]����� target = 2����ʱ���鿴�� [ - inf - inf - inf - inf 1 2 3]��
nums [ mid ] = 7��target < nums [ 0 ]��nums [ mid ] > nums [ 0 ]��һ�����ڣ�һ��С�ڣ��������ǲ���ͬһ�� nums [ mid ] = - inf������˸������
*/
int search(vector<int>& nums, int target) {
	int start = 0, end = nums.size();
	while (start < end)
	{
		int mid = start + (end - start) / 2;
		
		//int num = (nums[mid] < nums[0]) == (target < nums[0]) ? nums[mid] : target < nums[0] ? INT_MIN : INT_MAX;
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
			return mid;
	}
	return -1;
}

int main_33()
{
	vector<int> v{ 4, 5, 6, 7, 0, 1, 2 };
	int res = search(v, 0);
	cout << res << endl;
	system("pause");
	return 0;
}