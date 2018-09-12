#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

/*

Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.

349. Intersection of Two Arrays: https://leetcode.com/problems/intersection-of-two-arrays/description/
*/

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	vector<int> res;
	//map<int, int> map;
	unordered_map<int, int> map;
	for (auto i : nums1)
		map[i]++;
	for (auto i : nums2)
	{
		if (map[i]-- > 0)
			res.push_back(i);
	}
	return res;
}

int main_349()
{
	vector<int> v1 = { 1, 2, 2, 4 };
	vector<int> v2 = {  2, 2 };
	vector<int> res = intersection(v1, v2);

	system("pause");
	return 0;
}