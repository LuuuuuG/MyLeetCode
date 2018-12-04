#include <iostream>
#include <vector>
using namespace std;

/*
Given a non negative integer number num. For every numbers i in the range 0 ¡Ü i ¡Ü num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

338. Counting Bits: https://leetcode.com/problems/counting-bits/description/
*/

/*
5 & 4 = 101 & 100 = 4
6 & 5 = 110 & 101 = 4
7 & 6 = 111 & 110 = 6
8 & 7 = 1000 & 0111 = 0
*/
//dp solution:
vector<int> countBits(int num) {
	vector<int> dp(num + 1, 0);
	for (int i = 1; i <= num; ++i)
		dp[i] = dp[ i & (i - 1)] + 1;
	return dp;
}

vector<int> countBits2(int num) {
	vector<int> ans(num + 1, 0);
	for (int i = 1; i <= num; i++) {
		ans[i] = ans[i / 2] + i % 2;
	}
	return ans;
}

int main_338()
{
	vector<int> res = countBits(5);
	for (auto i : res)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}