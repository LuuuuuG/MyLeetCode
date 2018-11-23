#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*

Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

Example 1:

Input: "Hello"
Output: "hello"

Example 2:

Input: "here"
Output: "here"
Example 3:

Input: "LOVELY"
Output: "lovely"


709. To Lower Case: https://leetcode.com/problems/to-lower-case/description/
*/

string toLowerCase(string str) {
	for (int i = 0; i < str.size(); ++i)
	{
		if (isupper(str[i]))
			str[i] -= 'A' - 'a';		//str[i] = str[i] -'A' + 'a';
	}
	return str;
}

string toLowerCase2(string str) {
	for (char& c : str) {
		if (c >= 'A' && c <= 'Z') c += 32;
	}
	return str;
}

//using STL transform.
string toLowerCase3(string str) {

	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

int main_709()
{
	string s = "Hello World!";
	string res = toLowerCase(s);
	
	cout << res << endl;

	system("pause");
	return 0;
}