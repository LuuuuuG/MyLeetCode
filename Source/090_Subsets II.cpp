#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
	[2],
	[1],
	[1,2,2],
	[2,2],
	[1,2],
	[]
]

90. Subsets II: https://leetcode.com/problems/subsets-ii/description/
*/

void subsets(vector<int>& nums, int start, vector<int>& sub, vector<vector<int> >& res){
	res.push_back(sub);
	for (int i = start; i < nums.size(); ++i)
	{
		if (i > start && nums[i] == nums[i - 1]) continue;//skip duplicates
		sub.push_back(nums[i]);
		subsets(nums, i + 1, sub, res);
		sub.pop_back();
	}
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<vector<int> > res;
	vector<int> sub;
	sort(nums.begin(), nums.end());
	subsets(nums, 0, sub, res);
	return res;
}

int main_90()
{
	vector<int> v{ 1, 2, 2 };
	vector<vector<int> > res = subsetsWithDup(v);
	for (auto v : res)
	{
		for (auto i : v)
			cout << i << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}
