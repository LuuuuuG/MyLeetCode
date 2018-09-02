#include <iostream>
#include <vector>
using namespace std;

/*

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

283. Move Zeroes: https://leetcode.com/problems/move-zeroes/description/
*/

//20ms solution.
void moveZeroes(vector<int>& nums) {
	int j = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] != 0)
			nums[j++] = nums[i];
	}
	for (; j < nums.size(); ++j)
		nums[j] = 0;
}

//8ms solution.
void moveZeroes2(vector<int>& nums) {
	int pos = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] != 0)
		{
			swap(nums[pos++], nums[i]);
			//equals to:
			//int tmp = nums[i];
			//nums[i] = 0;
			//nums[pos++] = tmp;
		}
	}
}


int main_283()
{
	//vector<int> v = { 0, 1, 0, 3, 12 };
	vector<int> v = { 0, 0, 1, 0, 3, 12 };
	moveZeroes2(v);
	for (auto it : v)
		cout << it << " ";
	cout << endl;
	system("pause");
	return 0;
}