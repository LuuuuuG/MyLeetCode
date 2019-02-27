#include <iostream>
#include <000_util.h>
using namespace std;

/*
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4

Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5

148. Sort List: https://leetcode.com/problems/sort-list/description/
*/

class Solution1 {
public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;

		ListNode *slow = head;
		ListNode *fast = head;
		ListNode *pre = head;
		// step 1. cut the list to two halves
		while (fast && fast->next)
		{
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}

		pre->next = NULL;

		// step 2. sort each half
		ListNode *l1 = sortList(head);
		ListNode *l2 = sortList(slow);

		// step 3. merge l1 and l2
		return merge(l1, l2);

	}

	ListNode* merge(ListNode* l1, ListNode* l2)
	{
		ListNode *dummy = new ListNode(0);
		ListNode *tail = dummy;
		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				tail->next = l1;
				l1 = l1->next;
			}
			else
			{
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}

		tail->next = l1 ? l1 : l2;

		return dummy->next;
	}
};

class Solution2 {
public:
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *slow = head, *fast = head, *pre = head;
		while (fast && fast->next) {
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		pre->next = NULL;
		return merge(sortList(head), sortList(slow));
	}
	ListNode* merge(ListNode* l1, ListNode* l2) {
		if (!l1) return l2;
		if (!l2) return l1;
		if (l1->val < l2->val) {
			l1->next = merge(l1->next, l2);
			return l1;
		}
		else {
			l2->next = merge(l1, l2->next);
			return l2;
		}
	}
};