#include <iostream>
#include <vector>
//#include <000_util.h>
using namespace std;

/*
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

59. Spiral Matrix II: https://leetcode.com/problems/spiral-matrix-ii/
*/

vector<vector<int>> generateMatrix(int n) {
	vector<vector<int> > res(n, vector<int>(n , 0));
	int rowBegin =0, colBegin = 0;
	int rowEnd = n - 1, colEnd = n - 1;
	int tmp = 0;
	while (true)
	{
		//go right
		for (int col = colBegin; col <= colEnd; ++col)
			res[rowBegin][col] = ++tmp;
		if (++rowBegin > rowEnd) break;
		//go down
		for (int row = rowBegin; row <= rowEnd; ++row)
			res[row][colEnd] = ++tmp;
		if (--colEnd < colBegin) break;
		//go left
		for (int col = colEnd; col >= colBegin; --col)
			res[rowEnd][col] = ++tmp;
		if (--rowEnd < rowBegin) break;
		//go up
		for (int row = rowEnd; row >= rowBegin; --row)
			res[row][colBegin] = ++tmp;
		if (++colBegin > colEnd) break;
	}
	return res;
}

template<typename T>
void Vector2DPrint( vector<vector<T> > &vec)
{
	cout << "[" << endl;;
	for (auto vecs : vec)
	{
		cout << "[ ";
		for (auto i : vecs)
			cout << i << ", ";
		cout << " ]" << endl;
	}
	cout << "]" << endl;
}

int main_59()
{
	vector<vector<int> > res = generateMatrix(3);
	Vector2DPrint(res);



	system("pause");
	return 0;
}