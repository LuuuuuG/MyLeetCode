#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]

40. Combination Sum II: https://leetcode.com/problems/combination-sum-ii/description/
*/

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int> > res;
		vector<int> nums;
		combination(candidates, target, res, nums, 0);
		return res;
	}

	void combination(vector<int>& cands, int target, vector<vector<int> >& res, vector<int>& nums, int start)
	{
		if (target < 0) return;
		else if (target == 0) res.push_back(nums);
		else {
			for (int i = start; i < cands.size(); ++i)
			{
				if (i > start && cands[i] == cands[i - 1]) continue; // skip duplicates
				nums.push_back(cands[i]);
				combination(cands, target - cands[i], res, nums, i + 1);
				nums.pop_back();
			}
		}
	}
};