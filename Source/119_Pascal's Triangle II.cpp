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

/*
			 |
			V
    <- - -
	solve order from up to down, from right to left.
*/
vector<int> getRow(int rowIndex) {
	vector<int> res(rowIndex + 1);
	res[0] = 1;
	for (int i = 0; i < rowIndex + 1; ++i)
	{
		for (int j = i; j > 0; --j)
		{
			res[j] += res[j - 1];
		}
	}
	return res;
}

int main_119()
{
	vector<int> v = getRow(4);
	for (auto i : v)
		cout << i << " ";
	cout << endl;

	system("pause");
	return 0;
}