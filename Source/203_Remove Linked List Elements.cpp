/*
* [203] Remove Linked List Elements
*
* https://leetcode.com/problems/remove-linked-list-elements/description/
*
* algorithms
* Easy (34.20%)
* Total Accepted:    175.2K
* Total Submissions: 512.2K
* Testcase Example:  '[1,2,6,3,4,5,6]\n6'
*
* Remove all elements from a linked list of integers that have value val.
*
* Example:
*
*
* Input:  1->2->6->3->4->5->6, val = 6
* Output: 1->2->3->4->5
*
*
*/
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//3 line recursive solution
ListNode* removeElements(ListNode* head, int val) {
	if (head == NULL) return NULL;
	head->next = removeElements(head->next, val);
	return head->val == val ? head->next : head;
}

//two points.
ListNode* removeElements2(ListNode* head, int val) {
	ListNode *dummyHead = new ListNode(0);
	dummyHead->next = head;
	ListNode *prev = dummyHead;
	while (prev->next) {
		if (prev->next->val == val) {
			prev->next = prev->next->next;
		}
		else
			prev = prev->next;
	}
	return dummyHead->next;
}
