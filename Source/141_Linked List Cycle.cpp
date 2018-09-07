#include <iostream>

using namespace std;

/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

141. Linked List Cycle: https://leetcode.com/problems/linked-list-cycle/description/
*/


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

 
bool hasCycle(ListNode *head) {
	if (head == NULL || head->next == NULL)
		return false;
	ListNode *slow = head;
	ListNode *fast = head->next;
	while (slow != fast)
	{
		if (fast == NULL || fast->next == NULL)
			return false;
		slow = slow->next;
		fast = fast->next->next;
	}
	return true;
}

//https://www.youtube.com/watch?v=LUm2ABqAs1w
bool hasCycle2(ListNode *head) {
	ListNode *slow = head, *fast = head;

	while (slow != NULL && fast != NULL && fast->next != NULL) {

		slow = slow->next;               //Slow moves by 1 step
		fast = fast->next->next;        //Fast moves by two steps

		if (slow == fast) //If they meet then there is a loop
			return true;
	}

	return false; //No loop
}

