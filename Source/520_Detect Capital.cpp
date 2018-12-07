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
	bool start_upper = false;
	bool start_lower = false;
	if (word[0] > 'A' && word[0] < 'Z') start_upper = true;
	if (word[0] > 'a' && word[0] < 'z') start_lower = true;

	for (int i = 1; i < word.size(); ++i)
	{
		//todo: 
		//ok for:
		//1.upper + all  upper 
		//2. upper + all  lower
		//3. lower + all lower
	}
}

int main()
{

	system("pause");
	return 0;
}