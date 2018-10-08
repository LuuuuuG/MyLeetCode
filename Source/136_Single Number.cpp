#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


/*

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4

136. Single Number: https://leetcode.com/problems/single-number/description/
*/

//my 12ms solution:
int singleNumber(vector<int>& nums) {
	unordered_map<int, int> m;
	for (auto i : nums)
		m[i]++;
	for (auto i : m)
	{
		if (i.second == 1)
			return i.first;
	}
}

//4 ms solution
int singleNumber2(vector<int>& nums) {
	int singleNum = 0;
	for (int num : nums){
		singleNum ^= num;
	}
	return singleNum;
}

int main()
{
	vector<int> v = { 2, 2, 1, 1, 3 };
	int res = singleNumber2(v);
	cout << res << endl;
	system("pause");
	return 0;
}