#include <000_util.h>
#include <iostream>
#include <vector>
using namespace std;

/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
	[3],
	[1],
	[2],
	[1,2,3],
	[1,3],
	[2,3],
	[1,2],
	[]
]

78. Subsets: https://leetcode.com/problems/subsets/description/
*/

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> subs;
		vector<int> sub;
		subsets(nums, 0, sub, subs);
		return subs;
	}
private:
	void subsets(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs) {
		subs.push_back(sub);
		for (int i = start; i < nums.size(); i++)
		{
			sub.push_back(nums[i]);
			subsets(nums, i + 1, sub, subs);
			sub.pop_back();
		}
	}
};


int main_78()
{
	Solution s;
	vector<int> v{ 1, 2, 3 }; 
	vector<vector<int> > res = s.subsets(v);

	//Vector2DPrint(res);

	system("pause");
	return 0;
}