#include <iostream>
#include <vector>
using namespace std;

/*
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.



Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.


Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000

905. Sort Array By Parity: https://leetcode.com/problems/sort-array-by-parity/description/
*/

bool is_odd(int i)
{
	return i % 2;
}
vector<int> sortArrayByParity(vector<int>& A) 
{
	int i = 0, j = A.size() - 1;
	while ( i < j )
	{
		if (!is_odd(A[i]) ) ++i;
		if (is_odd(A[j]) ) --j;
		if (i < j && is_odd(A[i]) && !is_odd(A[j]))
		{
			swap(A[i], A[j]);
			++i;
			--j;
		}
	}
	return A;
}

vector<int> sortArrayByParity2(vector<int> &A) 
{
	/*
	for (int i = 0, j = 0; j < A.size(); j++)
			if (A[j] % 2 == 0) swap(A[i++], A[j]);
	*/
	int i = 0, j = A.size() - 1;
	while (i < j)
	if (A[i] % 2 == 0)
		++i;
	else
		swap(A[i], A[j--]);
	return A;
}

//easy way return a new array:
vector<int> sortArrayByParity3(vector<int>& A) 
{
	int size = A.size();
	vector<int> res(size, 0);
	int start = 0, end = size - 1;
	for (int i = 0; i < size; ++i) {
		if (A[i] % 2 == 1) {
			res[end--] = A[i];
		}
		else {
			res[start++] = A[i];
		}
	}
	return res;
}
int main_905()
{
	vector<int> v = { 0, 2, 1, 4 };
	vector<int> res = sortArrayByParity2(v);
	for (auto i : res)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}