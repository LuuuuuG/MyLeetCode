#include <iostream>
#include <vector>
using namespace std;

/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
	[7],
	[2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
	[2,2,2,2],
	[2,3,3],
	[3,5]
]

39. Combination Sum: https://leetcode.com/problems/combination-sum/description/
*/

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int> > res;
		vector<int> sub;
		subCombinSum(candidates, 0, target, sub, res);
		return res;
	}

	void subCombinSum(vector<int>& candidates, int start, int target, vector<int>& sub, vector<vector<int> >& res)
	{
		if (target < 0)
			return;
		else if (target == 0)
			res.push_back(sub);

		for (int i = start; i < candidates.size(); ++i)
		{
			sub.push_back(candidates[i]);
			subCombinSum(candidates, i, target - candidates[i], sub, res);//not i + 1 because we can reuse same elements
			sub.pop_back();
		}
	}
};