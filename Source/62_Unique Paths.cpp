#include <iostream>
#include <vector>
using namespace std;

/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

start	.	.	.	.	.	.	.
.	.	.	.	.	.	.	.	.
.	.	.	.	.	.	.	Finish

Note: m and n will be at most 100.

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28

62. Unique Paths: https://leetcode.com/problems/unique-paths/description/
*/

//2 DP solutions:
int uniquePaths(int m, int n) {
	if (m == 0 || n == 0) return 0;
	if (m == 1 || n == 1) return 1;
	vector<vector<int>> grid(m, vector<int>(n, 0));
	for (int i = 0; i < n; i++) grid[0][i] = 1;
	for (int i = 0; i < m; i++) grid[i][0] = 1;

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			grid[i][j] = grid[i][j - 1] + grid[i - 1][j];
		}
	}
	return grid[m - 1][n - 1];
}

int uniquePaths_dp(int m, int n) {
	vector<vector<int> > path(m, vector<int>(n, 1));
	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
			path[i][j] = path[i - 1][j] + path[i][j - 1];
	return path[m - 1][n - 1];
}

int main_62()
{
	int res = uniquePaths(1, 1);
	cout << res << endl;
	system("pause");
	return 0;
}