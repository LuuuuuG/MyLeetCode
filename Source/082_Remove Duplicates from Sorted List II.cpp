#include "000_util.h"
using namespace std;

/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3

82. Remove Duplicates from Sorted List II: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii
*/

ListNode* deleteDuplicates(ListNode* head) {
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode *prev = dummy;
	ListNode *cur = head;
	while (cur)
	{
		//move cur to end of duplicate.
		while (cur->next && cur->val == cur->next->val)
			cur = cur->next;

		if (prev->next == cur)//no duplication.
			prev = prev->next;
		else
			prev->next = cur->next;//skip all duplicate.

		cur = cur->next;
	}

	return dummy->next;
}