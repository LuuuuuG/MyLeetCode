#include <iostream>
#include <stack>
using namespace std;

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
20. Valid Parentheses: https://leetcode.com/problems/valid-parentheses/description/
*/

bool isValid(string s)
{
	stack<char> stk;
	for (auto i : s)
	{
		switch (i)
		{
		case '(':
		case '[':
		case '{':
			stk.push(i);
			break;
		case')' :
			if (stk.empty() || stk.top() != '(')
				return false;
			else
				stk.pop();
			break;
		case ']' :
			if (stk.empty() || stk.top() != '[')
				return false;
			else
				stk.pop();
			break;
		case '}':
			if (stk.empty() || stk.top() != '{')
				return false;
			else
				stk.pop();
			break;
		}
	}
	return stk.empty();
}

bool isValid2(string s)
{
	stack<char> stk;
	for (char c : s)
	{
		if (c == '(' || c == '[' || c == '{')
		{
			stk.push(c);
		}
		else
		{
			if (stk.empty())	return false;
			if (c == ')' && stk.top() != '(') return false;
			if (c == ']' && stk.top() != '[') return false;
			if (c == '}' && stk.top() != '{') return false;
			stk.pop();
		}
	}
	return stk.empty();
}
int main_20()
{
	string str = "{]()}";

	bool res = isValid(str);

	cout << "isValid = " << boolalpha << res << endl;

	system("pause");
	return 0;
}