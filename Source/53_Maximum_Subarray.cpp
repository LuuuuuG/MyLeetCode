#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

https://leetcode.com/problems/maximum-subarray/description/
It's about DP solution: https://blog.csdn.net/u013309870/article/details/75193592
*/
int maxSubArray(vector<int>& nums) {
	int ans = nums[0], sum = 0;
	for (auto it : nums){
		sum += it;
		ans = max(ans, sum);
		sum = max(sum, 0);
	}
	return ans;
}

//DP solution:
//maxSubArray(A, i) = A[i] + maxSubArray(A, i - 1) > 0 ? maxSubArray(A, i - 1) : 0;
int maxSubArray_dp(vector<int>& nums) {
	vector<int> dp(nums.size());
	dp[0] = nums[0];
	int ans = dp[0];

	for (int i = 1; i < nums.size(); ++i)
	{
		dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
		ans = max(ans, dp[i]);
	}
	return ans;
}

/*
Problem Description:
Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence. For example, given (6,-1,5,4,-7), the max sum in this sequence is 6 + (-1) + 5 + 4 = 14.


Input:
The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line starts with a number N(1<=N<=100000), then N integers followed(all the integers are between -1000 and 1000).


Output:
For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line contains three integers, the Max Sum in the sequence, the start position of the sub-sequence, the end position of the sub-sequence. If there are more than one result, output the first one. Output a blank line between two cases.

Sample Input:
2
5 6 -1 5 4 -7
7 0 6 -1 1 -6 7 -5

Sample Output:
Case 1:
14 1 4

Case 2:
7 1 6
http://acm.hdu.edu.cn/showproblem.php?pid=1003
*/

void maxSubArray2(void)
{
	int t, _case = 1;
	scanf("%d", &t);
	while (t--)
	{
		int n, dp = 0, maxSubSequence = -1001, begin = 1, end = 1, tmp = 1;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
		{
			int num;
			scanf("%d", &num);
			dp += num;
			if (dp > maxSubSequence)
			{
				maxSubSequence = dp;
				begin = tmp;
				end = i;
			}
			if (dp < 0)
			{
				dp = 0;
				tmp = i + 1;
			}
		}
		printf("Case %d:\n%d %d %d\n", _case++, maxSubSequence, begin, end);
		if (t)
			printf("\n");
	}
}

int main_53()
{
	vector<int> v = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	int res = maxSubArray_dp(v);
	cout << " sum = " << res << endl;

	//DP test 2.
	maxSubArray2();

	system("pause");
	return 0;
}
