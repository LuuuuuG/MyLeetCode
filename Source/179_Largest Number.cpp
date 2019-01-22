#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.

179. Largest Number: https://leetcode.com/problems/largest-number/description/
*/

string largestNumber(vector<int> &num) {
	sort(num.begin(), num.end(), [](int a, int b) {
		return to_string(a) + to_string(b) > to_string(b) + to_string(a);
	});
	string ans;
	for (int i = 0; i < num.size(); i++) {
		ans += to_string(num[i]);
	}
	return ans[0] == '0' ? "0" : ans;
}

int main_179()
{
	vector<int> v{ 3,30,34,5,9 };
	
	string res = largestNumber(v);
	cout << res << endl;
	system("pause");
	return 0;
}