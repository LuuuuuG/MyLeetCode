#include <iostream>
#include <vector>
using namespace std;

/*
26: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
27: https://leetcode.com/problems/remove-element/description/
ATTENTION!!!¡¾It doesn't matter what values are set beyond the returned length.¡¿@_@
*/

int removeDuplicates(vector<int>& nums)
{
	int i = 0;
	for (int n : nums)
		if (i == 0 || n > nums[i-1])
			nums[i++] = n;
	return i;

}

int removeElement(vector<int>& nums, int val) {
	int i = 0;
	for (int n : nums)
	if (n != val)
		nums[i++] = n;
	return i;
}


int main_26_27()
{
	vector<int> v = { 1, 2, 2, 3, 4, 4, 5, 5, 8 };

	//int res = removeDuplicates(v);
	int res = removeElement(v, 2);

	cout << "length = " << res << endl;
	for (int i = 0; i < res;++i)
		cout << " " << v[i];
	cout << endl;

	system("pause");
	return 0;
}