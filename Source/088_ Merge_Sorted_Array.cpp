#include <iostream>
#include <vector>
using namespace std;

/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]

88. Merge Sorted Array: https://leetcode.com/problems/merge-sorted-array/description/
*/

//my 8 ms solution: first add nums2 to nums1, then sort nums1.too slowly.....
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	nums1.resize(m);
	nums1.insert(nums1.begin() + m, nums2.begin(), nums2.end());
	for (int i = 0; i < nums1.size(); ++i)
		for (int j = 0; j < nums1.size() - i - 1; ++j)
			if (nums1[j] > nums1[j + 1])
				swap(nums1[j], nums1[j + 1]);
}
//4ms fantastic solution
void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int l = m + n;
	nums1.resize(m + n);

	while (m > 0 && n > 0) {
		if (nums1[m - 1] >= nums2[n - 1])
			nums1[--l] = nums1[--m];
		else
			nums1[--l] = nums2[--n];
	}

	while (n > 0) {
		nums1[--l] = nums2[--n];
	}
}


int main_88()
{
	vector<int> nums1 = {1, 2, 3, 0, 0, 0};
	vector<int>	nums2 = { 2, 5, 6 };
	int m = 3, n = 3;

	merge2(nums1, m, nums2, n);

	for (auto i : nums1)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}