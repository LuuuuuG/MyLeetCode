#ifndef __UTIL_H__
#define __UTIL_H__

#include <iostream>
#include <vector>
#include <string>
#include <cstdarg>
using namespace std;
/*
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
* Definition for a binary tree node.
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*--------------------------------tools-------------------------------*/
//vector
//template <typename T>
//void VectorPrint(vector<T> &vec);
//
//template <typename T>
//void Vector2DPrint(vector<vector<T> > &vec);

//List
ListNode *ListCreate(int count, ...);
void ListPrint(ListNode *head);

//Tree
TreeNode *TreeCreate(int count, ...);
void TreePrint(TreeNode *root);

/*--------------------------------tools-------------------------------*/


#endif //__UTIL_H__