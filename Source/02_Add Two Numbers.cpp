#include <iostream>
using namespace std;

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

2. Add Two Numbers: https://leetcode.com/problems/add-two-numbers/description/
*/


/*
* Definition for singly-linked list.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode tmpL(0), *p = &tmpL;
	int res = 0;
	while (l1 || l2 || res){
		if (l1){
			res += l1->val;
			l1 = l1->next;
		}
		if (l2){
			res += l2->val;
			l2 = l2->next;
		}
		p->next = new ListNode(res % 10);
		res /= 10;
		p = p->next;
	}
	return tmpL.next;
}


ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
	ListNode* root = new ListNode(0), *first = root;
	int carry = 0;

	while (l1 || l2)
	{
		int n1 = l1 ? l1->val : 0;
		int n2 = l2 ? l2->val : 0;
		int ans = n1 + n2 + carry;
		carry = ans / 10;
		root->next = new ListNode(ans % 10);
		root = root->next;
		if (l1) l1 = l1->next;
		if (l2) l2 = l2->next;
	}
	if (carry)
		root->next = new ListNode(1);

	return first->next;

}