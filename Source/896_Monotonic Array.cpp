#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

Return true if and only if the given array A is monotonic.



Example 1:

Input: [1,2,2,3]
Output: true
Example 2:

Input: [6,5,4,4]
Output: true
Example 3:

Input: [1,3,2]
Output: false
Example 4:

Input: [1,2,4,5]
Output: true
Example 5:

Input: [1,1,1]
Output: true


Note:

1 <= A.length <= 50000
-100000 <= A[i] <= 100000

896. Monotonic Array: https://leetcode.com/problems/monotonic-array/description/
*/

//ERROR: Time Limit Exceeded...QAQ
bool isMonotonic(vector<int>& A) {
	int count = A.size();
	if (count < 2) return true;
	int diff = A[0] - A[count - 1];

	for (int i = 0; i < count; ++i)
	{
		for (int j = i + 1; j < count; ++j)
		{
			if ((A[i] < A[j] && diff > 0) || (A[i] > A[j] && diff < 0) || (A[i] != A[j] && diff == 0))
				return false;
		}
	}
	return true;
}

//one pass
bool isMonotonic2(vector<int>& A) {
	bool increasing = true;
	bool decreasing = true;
	for (int i = 0; i < A.size() - 1; ++i)
	{
		if (A[i] > A[i + 1])
			increasing = false;
		if (A[i] < A[i + 1])
			decreasing = false;
	}
	return increasing || decreasing;
}

//STL is_sorted
bool isMonotonic(vector<int>& A){
	return is_sorted(A.cbegin(), A.cend()) || is_sorted(A.crbegin(), A.crend());
}
//Two pass
class solution1{
public:
	bool isMonotonic(vector<int>& A) {
		return increasing(A) || decreasing(A);
	}
	bool increasing(vector<int> &A)
	{
		for (int i = 0; i < A.size() - 1; ++i)
			if (A[i] > A[i + 1]) return false;
		return true;
	}
	bool decreasing(vector<int> &A)
	{
		for (int i = 0; i < A.size() - 1; ++i)
			if (A[i] < A[i + 1]) return false;
		return true;
	}
};

int main_896()
{
	vector<int> v = { 1, 3, 2, 1};
	//bool res = isMonotonic(v);
	solution1 s;
	bool res = s.isMonotonic(v);
	cout << boolalpha << res << endl;
	system("pause");
	return 0;
}