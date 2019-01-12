#include <iostream>
#include <vector>
using namespace std;

/*

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
	[2,4],
	[3,4],
	[2,3],
	[1,2],
	[1,3],
	[1,4],
]

77. Combinations: https://leetcode.com/problems/combinations/description/
*/

class Solution {
public:
	vector<vector<int>> combine(int n, int k)
	{
		vector<vector<int> > res;
		vector<int> sub;
		subCombin(res, sub, 1, n, k);
		return res;
	}

	void subCombin(vector<vector<int> > &res, vector<int>& sub, int start, int n, int k)
	{
		if (k == 0)
		{
			res.push_back(sub);
			return;
		}
		for (int i = start; i <= n; ++i)
		{
			sub.push_back(i);
			subCombin(res, sub, i + 1, n, k - 1);
			sub.pop_back();
		}
	}
};