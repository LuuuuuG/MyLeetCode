#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

198. House Robber: https://leetcode.com/problems/house-robber/description/
*/

//#define max(a, b) ((a)>(b)?(a):(b))
int rob(vector<int> num) {
	int a = 0;
	int b = 0;

	for (int i = 0; i<num.size(); i++)
	{
		if (i % 2 == 0)
		{
			a = max(a + num[i], b);
		}
		else
		{
			b = max(a, b + num[i]);
		}
	}

	return max(a, b);
}

/*-----------------------------------------
DP solution:
M(k) = money at the kth house
P(0) = 0
P(1) = M(1)
P(k) = max(P(k−2) + M(k), P(k−1))
-----------------------------------------*/
int rob2(vector<int>& nums) {
	int n = nums.size();
	if (!n){
		return 0;
	}
	if (n == 1){
		return nums[0];
	}

	if (n == 2){
		return max(nums[0], nums[1]);
	}

	vector<int> dp(n, 0);
	dp[0] = nums[0];
	dp[1] = max(nums[1], dp[0]);
	for (int i = 2; i<n; i++){
		dp[i] += max(dp[i - 2] + nums[i], dp[i - 1]);
	}
	return dp[n - 1];
}

int main_198()
{
	vector<int> v = { 2, 1, 1, 2 };
	int res = rob(v);
	cout << res << endl;

	system("pause");
	return 0;
}