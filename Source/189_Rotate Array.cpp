#include <iostream>
#include <vector>
using namespace std;


/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
Note:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?

189. Rotate Array: https://leetcode.com/problems/rotate-array/description/
*/

// 44ms QAQ
void rotate(vector<int>& nums, int k) {
	for (int i = 0; i < k; ++i)
	{
		nums.insert(nums.begin(), nums.back());
		nums.pop_back();
	}
}

// 12ms solution.
void rotate2(vector<int>& nums, int k) {
	k %= nums.size();
	reverse(nums.begin(), nums.end() - k);
	reverse(nums.end() - k, nums.end());
	reverse(nums.begin(), nums.end());
}

int main_189()
{
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7 };
	int k = 3;
	rotate2(v, k);
	for (auto it : v)
		cout << it << " ";
	cout << endl;
	system("pause");
	return 0;
}