#include <iostream>
#include <vector>
using namespace std;


/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]

216. Combination Sum III: https://leetcode.com/problems/combination-sum-iii/description/
*/


class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int> > res;
		vector<int> nums;
		comb(k, n, res, nums);
		return res;
	}

	void comb(int k, int target, vector<vector<int> >& res, vector<int>& nums)
	{
		if (target < 0 || k < 0) return;
		else if (target == 0 && k == 0) res.push_back(nums);
		else
		{
			for (int i = nums.empty() ? 1 : nums.back() + 1; i <= 9; ++i)
			{
				nums.push_back(i);
				comb(k - 1, target - i, res, nums);
				nums.pop_back();
			}
		}
	}
};

class Solution2 {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> ans;
		vector<int> temp;
		helper(k, n, ans, temp);
		return ans;
	}

	void helper(int k, int n, vector<vector<int>>& ans, vector<int>& temp) {
		if (n < 0 || k < 0) return;
		if (k == 0 && n == 0) {
			ans.push_back(temp);
			return;
		}
		int index = 1;
		if (temp.size() != 0) {
			index = temp.back() + 1;
		}
		for (int i = index; i <= 9; i++) {
			temp.push_back(i);
			helper(k - 1, n - i, ans, temp);
			temp.pop_back();
		}
	}
};