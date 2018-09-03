#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given an array of integers where 1 ¡Ü a[i] ¡Ü n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

448. Find All Numbers Disappeared in an Array: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
*/

vector<int> findDisappearedNumbers(vector<int>& nums) {
	int len = nums.size();
	for (int i = 0; i<len; i++) {
		int m = abs(nums[i]) - 1; // index start from 0
		// since some number appears more than once, the value at the corresponding index may have already been negative.
		//nums[m] = nums[m]>0 ? -nums[m] : nums[m];
		if (nums[m] > 0)
			nums[m] = -nums[m];
	}
	vector<int> res;
	for (int i = 0; i<len; i++) {
		if (nums[i] > 0) res.push_back(i + 1);
	}
	return res;

}

//84 ms solution
vector<int> findDisappearedNumbers2(vector<int>& nums) {
	vector<int> res;
	int i = 0;
	while (i < nums.size())
	{
		if (nums[nums[i] - 1] != nums[i])
			swap(nums[nums[i] - 1], nums[i]);
		else
			++i;
	}
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] != i + 1)
			res.push_back(i + 1);
	}
	return res;
}

int main_448()
{
	vector<int> v = { 4, 3, 2, 7, 8, 2, 3, 1 };
	vector<int> res = findDisappearedNumbers2(v);
	for (auto it : res)
		cout << it << " ";
	cout << endl;
	system("pause");
	return 0;
}