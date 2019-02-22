#include <iostream>
#include <vector>
using namespace std;

/*

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

70. Climbing Stairs: https://leetcode.com/problems/climbing-stairs/description/
*/

int climbStairs(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 2;

	vector<int> dp(n+1);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];
	return dp[n];
}


int main_70()
{
	int n = 3;
	int res = climbStairs(n);
	cout << res << endl;
	system("pause");
	return 0;
}