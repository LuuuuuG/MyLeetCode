#include <iostream>
#include <vector>
#include <cstdlib> //abs
#include <algorithm> //sort
#include <unordered_map>
#include <map>
using namespace std;

/*
Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.

Example 1:
Input: [3, 1, 4, 1, 5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:
Input:[1, 2, 3, 4, 5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:
Input: [1, 3, 1, 5, 4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
Note:
The pairs (i, j) and (j, i) count as the same pair.
The length of the array won't exceed 10,000.
All the integers in the given input belong to the range: [-1e7, 1e7].

532. K-diff Pairs in an Array: https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
*/

// NOT AC!!!
//int findPairs(vector<int>& nums, int k) {
//	int res = 0;
//	if (nums.empty())
//		return res;
//	sort(nums.begin(), nums.end());
//
//	for (int i = 0; i < nums.size(); ++i)
//	{
//		for (int j = i + 1; j < nums.size(); ++j)
//		{
//			if (k == 0 && nums[i] == nums[j])
//				res++;
//			else if (nums[i] == nums[i + 1])
//				break;
//			else if(nums[j] == nums[i] + k)
//				res++;
//		}
//	}
//	return res;
//}

//36ms solution.
int findPairs(vector<int>& nums, int k) {
	if (k < 0) return 0;
	//unordered_map<int, int> m;
	map<int, int> m;
	for (int n : nums) 
		m[n]++;
	int cnt = 0;
	for (auto p : m) {
		if ((!k && p.second > 1)
			|| (k && m.count(p.first + k))) ++cnt;
	}
	return cnt;
}

int findPairs2(vector<int>& nums, int k) {
	if (nums.size() == 0) return 0;

	sort(nums.begin(), nums.end());

	int cnt = 0;
	int old = nums[0] - 1;
	for (int i = 0, j = 1; j < nums.size();) {

		if (nums[i] == old) {
			++i;
			j = max(j, i + 1);
			continue;
		}

		int d = nums[j] - nums[i];

		if (d == k) {
			old = nums[i];
			++cnt;
			++i;
			++j;
		}
		else if (d < k) {
			++j;
		}
		else {
			++i;
			j = max(j, i + 1);
		}
	}

	return cnt;
}

int main_532()
{
	vector<int> v = { 3, 1, 4, 1, 5 };
	int res = findPairs2(v, 0);
	cout << res << endl;
	system("pause");
	return 0;
}