#include <iostream>
#include <vector>
using namespace std;

/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

167. Two Sum II - Input array is sorted: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
*/

// NOT AC QAQ
vector<int> twoSum(vector<int>& numbers, int target) {
	vector<int> res(2);
	for (int i = 0; i < numbers.size(); ++i)
	{
		for (int j = i + 1; j < numbers.size(); ++j)
		{
			if (numbers[j] == target - numbers[i])
			{
				res[0] = i;
				res[1] = j;
			}
		}
	}
	return res;
}

// 4ms solution.
vector<int> twoSum2(vector<int>& numbers, int target) {
	vector<int> res(2);
	int lo = 0, hi = numbers.size() - 1;
	while (lo < hi){
		int sum = numbers[lo] + numbers[hi];
		if (sum == target)
		{
			res[0] = lo + 1;
			res[1] = hi + 1;
			break;
		}
		else if (sum < target){
			lo++;
		}
		else {
			hi--;
		}
	}
	return res;
}

// 0ms solution
vector<int> twoSum3(vector<int>& numbers, int target) {
	for (int i = 0, j = numbers.size() - 1; i < j;)
	if (numbers[i] + numbers[j] < target)
		++i;
	else if (numbers[i] + numbers[j] > target)
		--j;
	else
		return{ i + 1, j + 1 };
}

int main_twoSum_II()
{

	vector<int> v = { 2, 7, 11, 15 };
	vector<int> res = twoSum2(v, 9);
	cout << res[0] << " " << res[1] << endl;
	system("pause");
	return 0;
}