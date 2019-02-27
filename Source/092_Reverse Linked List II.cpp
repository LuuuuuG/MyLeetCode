#include <000_util.h>
#include <iostream>
using namespace std;

/*

Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ¡Ü m ¡Ü n ¡Ü length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL

92. Reverse Linked List II: https://leetcode.com/problems/reverse-linked-list-ii/description/
*/

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == NULL || m == n)
		{
			return head;
		}
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* pre = dummy;
		for (int i = 0; i < m - 1; i++)
		{
			pre = pre->next;
		}
		ListNode* curr = pre->next;
		for (int i = 0; i < n - m; i++)
		{
			ListNode* move = curr->next;
			curr->next = move->next;
			move->next = pre->next;
			pre->next = move;
		}
		return dummy->next;
	}
};