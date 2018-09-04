#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000


485. Max Consecutive Ones: https://leetcode.com/problems/max-consecutive-ones/description/
*/

int findMaxConsecutiveOnes(vector<int>& nums) {
	int max_con = 0, cnt = 0;
	for (auto it : nums)
	{
		if (it == 1)
			max_con = max(max_con, ++cnt);
		else
			cnt = 0;
	}
	return max_con;
}


int main_485()
{
	vector<int> v = { 1, 1, 0, 1, 1, 1 };
	int res = findMaxConsecutiveOnes(v);
	cout << res << endl;
	system("pause");
	return 0;
}