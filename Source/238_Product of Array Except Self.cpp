#include <iostream>
#include <vector>
using namespace std;

/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

238. Product of Array Except Self: https://leetcode.com/problems/product-of-array-except-self/description/
*/

vector<int> productExceptSelf(vector<int>& nums) {
	vector<int> res(nums.size(), 1);
	int left = 1;
	for (int i = 0; i < nums.size(); ++i)
	{
		res[i] *= left;
		left *= nums[i];
	}
	int right = 1;
	for (int j = nums.size() - 1; j >= 0; --j)
	{
		res[j] *= right;
		right *= nums[j];
	}
	return res;
}

int main_238()
{
	vector<int> v = { 1, 2, 3, 4 };
	vector<int>res = productExceptSelf(v);
	for (auto i : res)
	{
		cout << i << " ";
	}
	system("pause");
	return 0;
}