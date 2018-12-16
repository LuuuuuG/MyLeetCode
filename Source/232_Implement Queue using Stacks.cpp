#include <iostream>
#include <stack>
using namespace std;

/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Example:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false
Notes:

1.You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
2.Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
3.You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

232. Implement Queue using Stacks: https://leetcode.com/problems/implement-queue-using-stacks/discuss/64206/Short-O(1)-amortized-C++-Java-Ruby
*/

class MyQueue {
	stack<int> input, output;
public:
	/** Initialize your data structure here. */
	MyQueue() {
		
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		input.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int tmp = peek();
		output.pop();
		return tmp;
	}

	/** Get the front element. */
	int peek() {
		if (output.empty()){
			while (input.size())
				output.push(input.top()), input.pop();
		}
		return output.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return input.empty() && output.empty();
	}
};