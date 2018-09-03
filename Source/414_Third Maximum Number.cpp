#include <iostream>
#include <vector>
#include <iterator>//std::advance
#include <set>
using namespace std;

/*
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
414. Third Maximum Number: https://leetcode.com/problems/third-maximum-number/description/
*/

//8ms solution
int thirdMax(vector<int>& nums) {
	//set<int> s;
	//for (auto i : nums)
	//	s.insert(i);
	set<int> s(nums.begin(), nums.end());
	auto it = s.end();

	if (s.size() < 3)
		advance(it, -1);
	else
		advance(it, - 3);
	return *it;
}

int thirdMax2(vector<int>& nums) {
	set<int> top3;
	for (int num : nums) {
		top3.insert(num);
		if (top3.size() > 3)
			top3.erase(top3.begin());
	}
	return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
}

int main_414()
{
	vector<int> v = { 6, 2, 1 };
	int res = thirdMax2(v);
	cout << res << endl;

	system("pause");
	return 0;
}