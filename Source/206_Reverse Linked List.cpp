#include <iostream>
using namespace std;

/*

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

206. Reverse Linked List : https://leetcode.com/problems/reverse-linked-list/description/
*/

/**
* Definition for singly-linked list.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverseList(ListNode* head) {
	ListNode* prev = NULL;
	ListNode* next = NULL;
	while (head)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	return prev;
}


