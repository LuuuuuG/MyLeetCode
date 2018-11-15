#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*

You have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  Then, either:

Each word after the identifier will consist only of lowercase letters, or;
Each word after the identifier will consist only of digits.
We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.

Return the final order of the logs.



Example 1:

Input: ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]


Note:

0 <= logs.length <= 100
3 <= logs[i].length <= 100
logs[i] is guaranteed to have an identifier, and a word after the identifier.

937. Reorder Log Files: https://leetcode.com/problems/reorder-log-files/description/
*/

bool myCompare(string a, string b)
{
	int i = a.find(' ');
	int j = b.find(' ');
	if (!isdigit(a[i + 1]) && !isdigit(b[j + 1]))
		return a.substr(i + 1) < b.substr(j + 1);
	else{
		if (!isdigit(a[i + 1])) return true;
		return false;
	}
}

vector<string> reorderLogFiles(vector<string>& logs) 
{
	stable_sort(logs.begin(), logs.end(), myCompare);
	return logs;
}


void testSort(vector<string>& vols, bool desc = false)
{
	stable_sort(vols.begin(), vols.end());
	if (desc)
		reverse(vols.begin(), vols.end());
}

int main_937()
{
	vector<string> vols = { "vol_test3", "vol_test2", "vol_lg", "vol_wtt" };
	testSort(vols);
	for (auto i : vols)
		cout << i << endl;

	cout << "========================================" << endl;

	vector<string> snapshots = { "2018-10-08", "2018-01-13", "2019-01-01" };
	testSort(snapshots, true);
	for (auto i : snapshots)
		cout << i << endl;

	cout << "========================================" << endl;

	vector<string> logs = { "a1 9 2 3 1", "g1 act car", "zo4 4 7", "ab1 off key dog", "a8 act zoo" };
	vector<string> res = reorderLogFiles(logs);
	for (auto i : logs)
		cout << i << endl;

	system("pause");
	return 0;
}