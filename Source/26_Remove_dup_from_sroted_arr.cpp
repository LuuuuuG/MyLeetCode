#include <iostream>
#include <vector>
using namespace std;

/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.
26: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example 1:

Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being 2.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,1,2,2,3,0,4,2], val = 2,

Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.

Note that the order of those five elements can be arbitrary.

It doesn't matter what values are set beyond the returned length.

27: https://leetcode.com/problems/remove-element/description/
ATTENTION!!!¡¾It doesn't matter what values are set beyond the returned length.¡¿@_@
*/

int removeDuplicates(vector<int>& nums)
{
	int i = 0;
	for (int n : nums)
		if (i == 0 || n > nums[i-1])
			nums[i++] = n;
	return i;

}

int removeDuplicates2(vector<int>& nums)
{
	if (nums.size() == 0) return 0;
	int i = 0;
	int j = 0;
	while (j < nums.size())
	{
		if (nums[i] == nums[j])
			++j;
		else
			nums[++i] = nums[j];// from index 1 to do replace.
	}
	return i + 1; // add index 0.
}

int removeElement(vector<int>& nums, int val) {
	int i = 0;
	for (int n : nums)
	if (n != val)
		nums[i++] = n;
	return i;
}


int main_26_27()
{
	vector<int> v = { 1, 2, 2, 3, 4, 4, 5, 5, 8 };

	int res = removeDuplicates2(v);
	//int res = removeElement(v, 2);

	cout << "length = " << res << endl;
	for (int i = 0; i < res;++i)
		cout << " " << v[i];
	cout << endl;

	system("pause");
	return 0;
}