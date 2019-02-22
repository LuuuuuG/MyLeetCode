#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*
https://leetcode.com/problems/roman-to-integer/description/
*/

int romanToInt(string s)
{
	unordered_map<char, int> T = {
		{ 'I', 1 },
		{ 'V', 5 },
		{ 'X', 10 },
		{ 'L', 50 },
		{ 'C', 100 },
		{ 'D', 500 },
		{ 'M', 1000 }
	};
	int sum = T[s.back()];
	for (int i = s.length() - 2; i >= 0; --i)
	{
		if (T[s[i]] < T[s[i + 1]])
			sum -= T[s[i]];
		else
			sum += T[s[i]];
	}
	return sum;
}

int main_013()
{
	string s = "VL";
	int res = romanToInt(s);

	cout << s << " transform to integer is : " << res << endl;

	system("pause");
	return 0;
}