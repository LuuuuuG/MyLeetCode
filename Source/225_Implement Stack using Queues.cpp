#include <iostream>
#include <queue>
using namespace std;

/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Example:

MyStack stack = new MyStack();

stack.push(1);
stack.push(2);
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false

225. Implement Stack using Queues: https://leetcode.com/problems/implement-stack-using-queues/description/
*/

class Stack {
	queue<int> que;
public:
	// Push element x onto stack.
	void push(int x) {
		que.push(x);
		for (int i = 1; i < que.size(); ++i) {
			que.push(que.front());
			que.pop();
		}
	}

	// Removes the element on top of the stack.
	void pop() {
		que.pop();
	}

	// Get the top element.
	int top() {
		return que.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		return que.empty();
	}
};

int main_225()
{
	Stack s;
	for (int i = 0; i < 10; ++i)
		s.push(i);

	system("pause");
	return 0;
}
