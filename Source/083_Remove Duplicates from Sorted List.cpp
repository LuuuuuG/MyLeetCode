#include <iostream>
using namespace std;

/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3

83. Remove Duplicates from Sorted List: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
*/
/*
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *list = head;
		while (list->next)
		{
			if (list->val == list->next->val)
			{
				ListNode *x = list->next;
				list->next = list->next->next;
				delete x;
			}
			else
				list = list->next;
		}
		return head;
	}
};