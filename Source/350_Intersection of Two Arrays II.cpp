#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

350. Intersection of Two Arrays II : https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
*/

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	vector<int> res;

	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());

	for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();)
	{
		if (nums1[i] == nums2[j])
		{
			res.push_back(nums1[i]);
			++i;
			++j;
		}
		else if (nums1[i] < nums2[j])
		{
			++i;
		}
		else
			++j;
	}
	return res;
}

#include <map>
#include <unordered_map>
//8ms solutions.
vector<int> intersect2(vector<int>& nums1, vector<int>& nums2) {
	//unordered_map<int, int> map;
	map<int, int> map;
	for (auto i : nums1)
		map[i]++;
	vector<int> res;
	for (auto i : nums2)
	{
		if (map[i] -- > 0)
			res.push_back(i);
	}
		return res;
}
int main_350()
{
	vector<int> num1 = { 4,9,5 };
	vector<int> num2 = { 9, 4, 9, 8, 4 };
	vector<int> res = intersect2(num1, num2);
	for (auto it : res)
		cout << it << " ";
	cout << endl;

	system("pause");
	return 0;
}