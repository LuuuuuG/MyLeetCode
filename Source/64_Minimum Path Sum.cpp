#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1¡ú3¡ú1¡ú1¡ú1 minimizes the sum.

64. Minimum Path Sum: https://leetcode.com/problems/minimum-path-sum/description/
*/

//my 8ms DP solution:
int minPathSum(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int> > dp(m, vector<int>(n, 0));
	int sum_i = 0, sum_j = 0;
	for (int i = 0; i < m; ++i)
	{
		sum_i += grid[i][0];
		dp[i][0] = sum_i;
	}
	for (int j = 0; j < n; ++j)
	{
		sum_j += grid[0][j];
		dp[0][j] = sum_j;
	}
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[m - 1][n - 1];
}

int minPathSum_2(vector<vector<int>>& grid) {
	int m = grid.size();
	if (m == 0)
		return 0;

	int n = grid[0].size();
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == 0 && j > 0) {
				grid[i][j] += grid[i][j - 1];
			}
			else if (j == 0 && i > 0) {
				grid[i][j] += grid[i - 1][j];
			}
			else if (i > 0 && j > 0) {
				grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
			}
		}
	}

	return grid[m - 1][n - 1];
}

int main_64()
{
	vector<vector<int> > v = { {1,3,1},{1,5,1},{4,2,1} };
	int res = minPathSum(v);
	cout << res << endl;
	system("pause");
	return 0;
}