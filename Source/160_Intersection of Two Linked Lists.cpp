#include <iostream>
using namespace std;

/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:       a1 ¡ú a2
                      ¨K
                         c1 ¡ú c2 ¡ú c3
                      ¨J
B:b1 ¡ú b2 ¡ú b3

begin to intersect at node c1.

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

160. Intersection of Two Linked Lists: https://leetcode.com/problems/intersection-of-two-linked-lists/description/
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	ListNode *cur1 = headA, *cur2 = headB;
	while (cur1 != cur2){
		cur1 = cur1 ? cur1->next : headB;
		cur2 = cur2 ? cur2->next : headA;
	}
	return cur1;
}

ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB)
{
	ListNode *p1 = headA;
	ListNode *p2 = headB;

	if (p1 == NULL || p2 == NULL) return NULL;

	while (p1 != NULL && p2 != NULL && p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;

		//
		// Any time they collide or reach end together without colliding 
		// then return any one of the pointers.
		//
		if (p1 == p2) return p1;

		//
		// If one of them reaches the end earlier then reuse it 
		// by moving it to the beginning of other list.
		// Once both of them go through reassigning, 
		// they will be equidistant from the collision point.
		//
		if (p1 == NULL) p1 = headB;
		if (p2 == NULL) p2 = headA;
	}

	return p1;
}