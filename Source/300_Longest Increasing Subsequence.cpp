#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Note:
There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.

Follow up: 
Could you improve it to O(n log n) time complexity?

300. Longest Increasing Subsequence: https://leetcode.com/problems/longest-increasing-subsequence/description/
*/

//¶þ·ÖËÑË÷£º
int lengthOfLIS(vector<int>& nums) {
	vector<int> res(nums.size(), 0);
	int size = 0;
	for (int x : nums)
	{
		int start = 0, end = size;
		while (start != end)
		{
			int mid = start + (end - start) / 2;
			if (res[mid] < x)
				start = mid + 1;
			else
				end = mid ;
		}
		res[start] = x;
		if (start == size) 
			++size;
	}
	return size;
}

//24ms 
/// Dynamic Programming
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
int lengthOfLIS2(vector<int>& nums) {

	if (nums.size() == 0)
		return 0;

	// memo[i] is the length of the longest increasing sequence end in nums[i]
	vector<int> memo(nums.size(), 1);
	for (int i = 1; i < nums.size(); i++)
		for (int j = 0; j < i; j++)
			if (nums[i] > nums[j])
				memo[i] = max(memo[i], 1 + memo[j]);
				

	int res = memo[0];
	for (int i = 1; i < nums.size(); i++)
		res = max(res, memo[i]);

	return res;
}

//lower_bound
int lengthOfLIS3(vector<int>& nums) {
	vector<int> result;

	for (auto x : nums)
	{
		auto iter = lower_bound(result.begin(), result.end(), x);
		
		if (iter == result.end())
			result.push_back(x);
		else
			*iter = x;
	}

	return result.size();
}

void test_lower_bound()
{
	vector<int> v{ 1,3,1,3,5,8,7,9 };
	//auto it = lower_bound(v.begin(), v.end(), 2) - v.begin();//1
	 auto it = lower_bound(v.begin(), v.end(), 3) - v.begin();//3
	 it = lower_bound(v.begin(), v.end(), 1) - v.begin();//2
	 it = lower_bound(v.begin(), v.end(), 4) - v.begin();//4
	 it = lower_bound(v.begin(), v.end(), 6) - v.begin();//5
	cout << "\n------------------------------------------\n" << endl;
	
	 it = upper_bound(v.begin(), v.end(), 10) - v.begin();//8
	 it = upper_bound(v.begin(), v.end(), 6) - v.begin();//5
	 it = upper_bound(v.begin(), v.end(), 3) - v.begin();//4


	 int myints[] = { 10,20,30,30,20,10,10,20 };
	 std::vector<int> vec(myints, myints + 8);           // 10 20 30 30 20 10 10 20

	 std::sort(vec.begin(), vec.end());                // 10 10 10 20 20 20 30 30

	 std::vector<int>::iterator low, up;
	 low = std::lower_bound(vec.begin(), vec.end(), 20); //  first  >= 20
	 up = std::upper_bound(vec.begin(), vec.end(), 20); //       first > 20

	 std::cout << "lower_bound at position " << (low - vec.begin()) << '\n';//3
	 std::cout << "upper_bound at position " << (up - vec.begin()) << '\n';//6

}

int main_300()
{
	vector<int> v{ 10,9,2,5,3,7,101,18 };

	test_lower_bound();
	int res = lengthOfLIS3(v);
	cout << res << endl;
	system("pause");
	return 0;
}