#include <iostream>
#include <vector>
using namespace std;

/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

169. Majority Element: https://leetcode.com/problems/majority-element/description/
*/

//Time Limit Exceeded ???
int majorityElement(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i)
		for (int j = 0; j < nums.size() - i - 1; ++j)
			if (nums[j] > nums[j + 1])
				swap(nums[j], nums[j + 1]);
	return nums[nums.size() / 2];
}

int majorityElement2(vector<int>& nums) {
	int major = nums[0], count = 1;
	for (int i = 1; i < nums.size(); ++i)
	{
		if (count == 0)
		{
			count++;
			major = nums[i];
		}
		else if (major == nums[i])
			count++;
		else
			count--;
	}
	return major;
}

int main_169()
{
	vector<int> v = { 1, 1, 2, 3, 1, 2, 2, 2 };
	int res = majorityElement2(v);
	cout << res << endl;

	system("pause");
	return 0;
}