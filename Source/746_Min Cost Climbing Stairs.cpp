#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:

Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.

Example 2:

Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].

Note:
  1.cost will have a length in the range [2, 1000].
  2.Every cost[i] will be an integer in the range [0, 999].

746. Min Cost Climbing Stairs: https://leetcode.com/problems/min-cost-climbing-stairs/description/
*/

//12 ms:
int minCostClimbingStairs0(vector<int>& cost) {
	int n = cost.size();
	vector<int> dp(n+1, 0);
	for (int i = 2; i <= n; ++i)
		dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]); //equals to ==> min(+2 steps, +1 step)
	return dp[n];
}

int minCostClimbingStairs(vector<int>& cost) {
	int n = (int)cost.size();
	vector<int> dp(n);
	dp[0] = cost[0];
	dp[1] = cost[1];
	for (int i = 2; i < n; ++i)
		dp[i] = cost[i] + min(dp[i - 2], dp[i - 1]);
	return min(dp[n - 2], dp[n - 1]);
}

//4 ms solution:
int minCostClimbingStairs2(vector<int>& cost) {
	int f1 = 0, f2 = 0;
	for (int k = cost.size() - 1; k >= 0; --k) {
		int f0 = cost[k] + min(f1, f2);
		f2 = f1;
		f1 = f0;
	}
	return min(f1, f2);
}

int main_746()
{
	vector<int> cost = { 1,0,0,0 };
	int res = minCostClimbingStairs(cost);
	cout << res << endl;
	system("pause");
	return 0;
}