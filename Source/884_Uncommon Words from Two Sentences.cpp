#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;
/*
We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Return a list of all uncommon words.

You may return the list in any order.



Example 1:

Input: A = "this apple is sweet", B = "this apple is sour"
Output: ["sweet","sour"]
Example 2:

Input: A = "apple apple", B = "banana"
Output: ["banana"]


Note:

0 <= A.length <= 200
0 <= B.length <= 200
A and B both contain only spaces and lowercase letters.

884. Uncommon Words from Two Sentences: https://leetcode.com/problems/uncommon-words-from-two-sentences/description/
*/

vector<string> uncommonFromSentences(string A, string B) {
	// combine the two strings for simplicity and construct an istringstream
	istringstream combined(A + " " + B);

	// our word will be put in this variable by getline
	string word;

	// keep track of word occurrences
	unordered_map<string, int> counts;

	// get the next word and increase its count in our map
	while (getline(combined, word, ' '))
		counts[word] += 1;

	// put the words with an occurrence of 1 in our result vector
	vector<string> result;
	for (auto &p : counts) {
		if (p.second == 1)
			result.push_back(p.first);
	}

	return result;
}

vector<string> uncommonFromSentences2(string A, string B) {
	unordered_map<string, int> count;
	istringstream iss(A + " " + B);
	while (iss >> A) count[A]++;
	vector<string> res;
	for (auto w : count)
	if (w.second == 1)
		res.push_back(w.first);
	return res;
}

//implement split using getline.
vector<string> testSplit(string s, char delim)
{
	vector<string> res;
	istringstream ss(s);
	string word;

	while (getline(ss, word, delim))
	{
		//cout << word << endl;
		res.push_back(word);
	}
	return res;
}

int main_884()
{
	string s = "this apple is sweet";
	string s2 = "this apple is apple";

	//testSplit(s, ' ');
	system("pause");
	return 0;
}