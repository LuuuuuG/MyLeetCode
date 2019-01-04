#include <iostream>
#include <vector>
using namespace std;

/*

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?


Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

63. Unique Paths II: https://leetcode.com/problems/unique-paths-ii/description/
*/

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();

	vector<vector<int> > dp(m, vector<int>(n, 0));
	for (int i = 0; i < m; ++i)
	{
		if (obstacleGrid[i][0]) break;
		else dp[i][0] = 1;
	}
	for (int j = 0; j < n; ++j)
	{
		if (obstacleGrid[0][j]) break;
		else dp[0][j] = 1;
	}

	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (!obstacleGrid[i][j])
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m - 1][n - 1];
}

int uniquePathsWithObstacles_dp(vector<vector<int> > &obstacleGrid) {
	int m = obstacleGrid.size(), n = obstacleGrid[0].size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	dp[0][1] = 1;//to make dp[1][1] which is the first element in the real grid equal to 1
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			if (!obstacleGrid[i - 1][j - 1])
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	return dp[m][n];
}

int main_63()
{
	vector<vector<int> > v = { {1,0} };
	int res = uniquePathsWithObstacles_dp(v);
	cout << res << endl;
	system("pause");
	return 0;
}