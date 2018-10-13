#include <iostream>
using namespace std;

/*

Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
addAtTail(val) : Append a node of value val to the last element of the linked list.
addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
Example:

MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
linkedList.get(1);            // returns 2
linkedList.deleteAtIndex(1);  // now the linked list is 1->3
linkedList.get(1);            // returns 3
Note:

All values will be in the range of [1, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in LinkedList library.

707. Design Linked List: https://leetcode.com/problems/design-linked-list/description/
*/

struct Node {
	int val;
	Node *next;
	Node(int x) : val(x), next(NULL) {}
};

class MyLinkedList {
	int size;
	Node* head;
	Node* tail;
public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index >= size || index < 0) 
			return -1;
		Node* cur = new Node(0);
		cur = head;
		for (int i = 0; i < index; ++i)
			cur = cur->next;
		return cur->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		Node* temp = new Node(0);
		temp->val = val;
		temp->next = head;
		head = temp;
		if (size == 0)
			tail = temp;
		++size;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		Node* temp = new Node(0);
		temp->val = val;
		if (size == 0)
		{
			head = temp;
			tail = temp;
		}
		tail->next = temp;
		tail = temp;
		++size;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index>size || index < 0) return;
		else if (index == 0) {
			addAtHead(val);
			return;
		}
		else if (index == size) {
			addAtTail(val);
			return;
		}
		Node *cur = new Node(0);
		cur = head;
		for (int i = 0; i<index - 1; ++i){
			cur = cur->next;
		}
		Node *temp = new Node(0);
		temp->val = val;
		temp->next = cur->next;
		cur->next = temp;
		++size;
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index >= size || index < 0) return;
		else if (index == 0){
			head = head->next;
			--size;
			return;
		}
		Node *cur = new Node(0);
		cur = head;
		for (int i = 0; i<index - 1; ++i){
			cur = cur->next;
		}
		cur->next = cur->next->next;
		if (index == size - 1) tail = cur;
		--size;
	}
};

/**
* Your MyLinkedList object will be instantiated and called as such:
* MyLinkedList obj = new MyLinkedList();
* int param_1 = obj.get(index);
* obj.addAtHead(val);
* obj.addAtTail(val);
* obj.addAtIndex(index,val);
* obj.deleteAtIndex(index);
*/

int main_707()
{
	MyLinkedList* ml = new MyLinkedList();
	ml->addAtHead(1);
	ml->addAtTail(3);
	ml->addAtIndex(1, 2);  // linked list becomes 1->2->3
	int res = ml->get(1);            // returns 2
	cout << "res = " << res << endl;
	ml->deleteAtIndex(1);  // now the linked list is 1->3
	res = ml->get(1);            // returns 3
	cout << "res = " << res << endl;
	system("pause");
	return 0;
}