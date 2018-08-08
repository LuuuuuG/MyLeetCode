#include <iostream>
#include <vector>
using namespace std;

/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

Example:

Input: 5
Output:
[
	 [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

118. Pascal's Triangle: https://leetcode.com/problems/pascals-triangle/description/
*/


vector<vector<int>> generate(int numRows) {
	vector<vector<int> > res(numRows);
	for (int i = 0; i < numRows; ++i)
	{
		res[i].resize(i + 1);
		res[i][0] = res[i][i] = 1;
		for (int j = 1; j < i; ++j)
			res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
	}
	return res;
}


int main()
{

	
	vector<vector<int> >res = generate(5);

	system("pause");
	return 0;
}