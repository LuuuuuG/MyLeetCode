#include <iostream>
#include <vector>
using namespace std;

/*
Note that the row index starts from 0.
    [1],
   [1,1],
  [1,2,1],
 [1,3,3,1],
[1,4,6,4,1]

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
119. Pascal's Triangle II: https://leetcode.com/problems/pascals-triangle-ii/description/

*/
vector<int> getRow(int rowIndex) {
	
	vector<int> res, res_1;
	if (rowIndex == 0)
		return { 1 };
	res.resize(rowIndex);
	res_1.resize(rowIndex - 1);
	
	while (rowIndex--){
		res[0] = res[rowIndex - 1] = 1;
		for (int i = 1; i < res.size() - 1; ++i)
		{
			res[i] = res_1[i - 1] + res_1[i];
		}

	}
	return res;
}

int main()
{
	vector<int> v = getRow(3);
	for (auto i : v)
		cout << i << " ";

	system("pause");
	return 0;
}