#include <iostream>
#include <vector>
#include "000_util.h"
using namespace std;

/*


Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

54. Spiral Matrix: https://leetcode.com/problems/spiral-matrix/
*/

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> res;
	if (matrix.empty()) return res;

	int rowBegin = 0, rowEnd = matrix.size() - 1;
	int colBegin = 0, colEnd = matrix[0].size() - 1;

	while (true)
	{
		//go right
		for (int col = colBegin; col <= colEnd; ++col)
			res.push_back(matrix[rowBegin][col]);
		if(++rowBegin > rowEnd) break;
		//go down
		for (int row = rowBegin; row <= rowEnd; ++row)
			res.push_back(matrix[row][colEnd]);
		if(--colEnd < colBegin) break;
		//go left
		for (int col = colEnd; col >= colBegin; --col)
			res.push_back(matrix[rowEnd][col]);
		if(--rowEnd < rowBegin) break;
		//go up
		for (int row = rowEnd; row >= rowBegin; --row)
			res.push_back(matrix[row][colBegin]);
		if(++colBegin > colEnd) break;
	}
	return res;

}


int main_54()
{
	vector<vector<int> > v = 
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9,10,11,12}
	};
	vector<int> res = spiralOrder(v);
	for (auto i : res)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}