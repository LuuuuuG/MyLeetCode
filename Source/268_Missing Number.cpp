#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

268. Missing Number: https://leetcode.com/problems/missing-number/description/
*/

//my 24ms solution.
int missingNumber(vector<int>& nums) {
	nums.resize(nums.size() + 1, INT_MAX);
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] != i)
			return i;
	}
	return -1;
}

/*
Index	0	1	2	3
Value	0	1	3	4
missing =4…(0…0)…(1…1)…(2…3)…(3…4)
			=(4…4)…(0…0)…(1…1)…(3…3)…2
			=0…0…0…0…2
			=2
*/

//28ms using XOR.
int missingNumber2(vector<int>& nums) {
	int missing = nums.size();
	for (int i = 0; i < nums.size(); i++) {
		missing ^= i ^ nums[i];
	}
	return missing;
}

int main_268()
{
	vector<int> v = { 9, 6, 4, 2, 3, 5, 7, 0, 1 };
	int res = missingNumber2(v);

	cout << res << endl;
	system("pause");
	return 0;
}