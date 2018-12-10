#include <iostream>
#include <string>
using namespace std;

/*

You are given a string representing an attendance record for a student. The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True

Example 2:
Input: "PPALLL"
Output: False

551. Student Attendance Record I: https://leetcode.com/problems/student-attendance-record-i/description/
*/

bool checkRecord(string s) {
	int cnt_A = 0, cnt_L = 0;
	for (auto t : s)
	{
		if (t == 'A') ++cnt_A;
		if (t == 'L') ++cnt_L;
		else cnt_L = 0;
		if (cnt_A > 1 || cnt_L > 2) return false;
	}
	return true;
}

int main_551()
{
	string s = "PPALLP";
	bool res = checkRecord(s);
	cout << boolalpha << res << endl;

	system("pause");
	return 0;
}