#include <000_util.h>
#include <iostream>
#include <list>
using namespace std;

/*

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

23. Merge k Sorted Lists: https://leetcode.com/problems/merge-k-sorted-lists/description/
*/

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty()) return NULL;
		while (lists.size() > 1)
		{
			lists.push_back(merge(lists[0], lists[1]));
			lists.erase(lists.begin());
			lists.erase(lists.begin());
		}
		return lists.front();
	}

	ListNode* merge(ListNode *l1, ListNode *l2)
	{
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;

		if (l1->val < l2->val)
		{
			l1->next = merge(l1->next, l2);
			return l1;
		}
		else
		{
			l2->next = merge(l1, l2->next);
			return l2;
		}
	}
};