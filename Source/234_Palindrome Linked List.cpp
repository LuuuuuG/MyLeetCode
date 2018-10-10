#include <iostream>
#include <stack>
using namespace std;

/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false

Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

234. Palindrome Linked List: https://leetcode.com/problems/palindrome-linked-list/description/
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//not AC QAQ!
bool isPalindrome(ListNode* head) {
	stack<int> stk;
	if (head == NULL || head->next == NULL)
		return false;
	while (head)
	{
		if (stk.top() == head->val)
			stk.pop();
		else
			stk.push(head->val);
		head = head->next;
	}
	if (stk.empty())
		return true;
	return false;
}

/*
In the beginning, set two pointers fast and slow starting at the head.

1 -> 1 -> 2 -> 1 -> null
sf
(1) Move: fast pointer goes to the end, and slow goes to the middle.

1 -> 1 -> 2 -> 1 -> null
s          f
(2) Reverse: the right half is reversed, and slow pointer becomes the 2nd head.

1 -> 1    null <- 2 <- 1
h			                     s
(3) Compare: run the two pointers head and slow together and compare.

1 -> 1    null <- 2 <- 1
		h              s
*/
ListNode* reverseList234(ListNode *head);
bool isPalindrome2(ListNode* head) {
	ListNode *fast = head, *slow = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	if (fast != NULL)
		slow = slow->next; //let right half smaller.
	slow = reverseList234(slow);
	while (slow != NULL)
	{
		if (head->val != slow->val)
			return false;
		head = head->next;
		slow = slow->next;
	}
	return true;
}
ListNode* reverseList234(ListNode *head)
{
	ListNode *prev = NULL;
	ListNode *next = NULL;
	while (head)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	return prev;
}
