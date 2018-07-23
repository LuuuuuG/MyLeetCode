#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

https://leetcode.com/problems/maximum-subarray/description/
It's about DP solution: https://blog.csdn.net/u013309870/article/details/75193592
*/
int maxSubArray(vector<int>& nums) {
	int ans = nums[0],sum = 0;
	for (auto it : nums){
		sum += it;
		ans = max(sum, ans);
		sum = max(sum, 0);
	}
	return ans;
}

int main_53()
{
	vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int res = maxSubArray(v);

	cout << " sum = " << res << endl;

	getchar();
	return 0;
}
