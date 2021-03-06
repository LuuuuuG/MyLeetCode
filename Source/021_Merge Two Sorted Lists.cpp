#include <iostream>
using namespace std;

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

21. Merge Two Sorted Lists: https://leetcode.com/problems/merge-two-sorted-lists/description/
*/

/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode dummy(INT_MIN);
		ListNode *tail = &dummy;

		while (l1 && l2) {
			if (l1->val < l2->val) {
				tail->next = l1;
				l1 = l1->next;
			}
			else {
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}

		tail->next = l1 ? l1 : l2;
		return dummy.next;
	}
};

//8ms recursion solution.
class Solution2 {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 && l2) {
			if (l1->val <= l2->val) {
				ListNode* result = l1;
				result->next = mergeTwoLists(l1->next, l2);
				return result;
			}
			else {
				ListNode* result = l2;
				result->next = mergeTwoLists(l1, l2->next);
				return result;
			}
		}
		if (l1) {
			return l1;
		}
		if (l2) {
			return l2;
		}
		return NULL;
	}
};