#include <000_util.h>

/*

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

19. Remove Nth Node From End of List: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode *fast = dummy, *slow = dummy;
	for (int i = 0; i < n; ++i)
		fast = fast->next;
	while (fast->next)
	{
		slow = slow->next;
		fast = fast->next;
	}
	slow->next = slow->next->next;

	return dummy->next;
}