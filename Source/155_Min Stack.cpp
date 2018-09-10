#include <iostream>
#include <stack>
using namespace std;

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

155. Min Stack: https://leetcode.com/problems/min-stack/description/
*/

class MinStack {
	stack<int> s1;
	stack<int> s2;
public:
	/** initialize your data structure here. */
	MinStack() {
	}

	void push(int x) {
		s1.push(x);
		if (s2.empty() || x <= getMin())
			s2.push(x);
	}

	void pop() {
		if (s1.top() == getMin())
			s2.pop();
		s1.pop();
	}

	int top() {
		return s1.top();
	}

	int getMin() {
		return s2.top();
	}
};

int main_155()
{
	MinStack minStack;// = new MinStack();
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	minStack.getMin();   //--> Returns - 3.
	minStack.pop();
	int top = minStack.top();			//--> Returns 0.
	int mini = minStack.getMin();   // --> Returns - 2.

	system("pause");
	return 0;
}