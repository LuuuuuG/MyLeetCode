#include <iostream>
#include <string>
#include <time.h>
using namespace std;

/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".

344. Reverse String: https://leetcode.com/problems/reverse-string/description/
*/

//8ms ...
string reverseString(string s) {
	string res = "";
	for (int i = s.size() - 1; i >= 0; --i)
		res += s[i];
	return res;
}

string reverseString2(string s) {
	int i = 0, j = s.size() - 1;
	while (i < j){
		swap(s[i++], s[j--]);
	}

	return s;
}

int main_344()
{
	string s = "Hello";
	clock_t start = clock();
	string res = reverseString(s);
	clock_t end = clock();

	cout << "res = " << res << endl << "time : " << (end - start) * 1.0 / CLOCKS_PER_SEC * 1000 << endl;
	system("pause");
	return 0;
}