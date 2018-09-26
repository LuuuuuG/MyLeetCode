#include <iostream>
#include <vector>
using namespace std;

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

1. Two sum: https://leetcode.com/problems/two-sum/description/
*/

vector<int> twoSum01(vector<int>& nums, int target) {
	vector<int> res;
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = i + 1; j < nums.size(); ++j)
		{
			if (nums[i] == target - nums[j])
			{
				res.push_back(i);
				res.push_back(j);
			}
		}
	}
	return res;
}

#include <map>
vector<int> twoSum02(vector<int>& nums, int target) {
	map<int, int> hash;
	for (int i = 0; i<nums.size(); i++){
		int complement = target - nums[i];
		if (hash.find(complement) != hash.end() && hash[i] != i){
			return vector<int> {hash[complement], i};
		}
		hash[nums[i]] = i;
	}
}

int main_01()
{
	vector<int> v = { 2, 7, 11, 15 };
	vector<int> ret = twoSum02(v, 9);
	cout << ret[0] << " " << ret[1] << endl;
	system("pause");
	return 0;
}