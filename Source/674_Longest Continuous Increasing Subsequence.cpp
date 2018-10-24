#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3.
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4.
Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1.
Note: Length of the array will not exceed 10,000.

674. Longest Continuous Increasing Subsequence: https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
*/

int findLengthOfLCIS(vector<int>& nums) {
	
	if (nums.size() <= 1)
		return nums.size();
	int maxlen = -1;
	int cnt = 1;
	for (int i = 0; i < nums.size() - 1;)
	{
		if (nums[i + 1] > nums[i])
		{
			++cnt;
			++i;
		}
		else
		{
			i += 1;
			cnt = 1;
		}
		maxlen = max(cnt, maxlen);
	}
	return maxlen;
}

//optimize solution:
int findLengthOfLCIS2(vector<int>& nums) {
	int res = 0, cnt = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (i == 0 || nums[i - 1] < nums[i]) res = max(res, ++cnt);
		else cnt = 1;
	}
	return res;
}

int main_674()
{
	vector<int> v = { 1, 3, 5, 4, 7 };
	int res = findLengthOfLCIS2(v);
	cout << res << endl;
	system("pause");
	return 0;
}