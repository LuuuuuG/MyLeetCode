#include <iostream>
#include <vector>
using namespace std;

/*
35: https://leetcode.com/problems/search-insert-position/description/
*/
int searchInsert(vector<int>& nums, int target)
{
	int cnt = 0;
	for (auto n : nums)
	{
		if (n < target)
			cnt++;
	}
	return cnt;
}


int main_35()
{
	vector<int> v = { 1, 3, 5, 6 };
	int res = searchInsert(v,0);

	cout << "Insert position is : " << res << endl;

	system("pause");
	return 0;
}