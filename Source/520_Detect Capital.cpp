#include <iostream>
#include <string>
using namespace std;

/*

Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

1.All letters in this word are capitals, like "USA".
2.All letters in this word are not capitals, like "leetcode".
3.Only the first letter in this word is capital if it has more than one letter, like "Google".

Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True

Example 2:
Input: "FlaG"
Output: False

520. Detect Capital: https://leetcode.com/problems/detect-capital/description/
*/

bool detectCapitalUse(string word) {
	if (word.size() == 0) return false;

	bool has_upper = false, has_lower = false;

	for (int i = 1; i < word.size(); ++i)
	{
		if (isupper(word[i])) has_upper = true;
		if (islower(word[i])) has_lower = true;
	}
	if (islower(word[0]) && has_upper) return false;
	if (isupper(word[0]) && has_upper && has_lower) return false;

	return true;
}

bool detectCapitalUse2(string word) {
	for (int i = 1; i < word.size(); i++){
		if (isupper(word[1]) != isupper(word[i]) ||
			islower(word[0]) && isupper(word[i])) return false;
	}
	return true;
}

int main_520()
{
	string word = "aeafweA";
	bool res = detectCapitalUse(word);
	cout << boolalpha << res << endl;
	system("pause");
	return 0;
}