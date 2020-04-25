#include "000_util.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define null INT_MAX
/*
Given a tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

		  5
		/  \
	  3     6
	 / \      \
   2    4     8
  /            / \
1            7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
	\
	 3
	  \
	   4
		\
		 5
		  \
		   6
			\
			 7
			  \
			   8
				\
				 9
Note:

The number of nodes in the given tree will be between 1 and 100.
Each node will have a unique integer value from 0 to 1000.

897. Increasing Order Search Tree: https://leetcode.com/problems/increasing-order-search-tree/description/
*/

#if 0
// reorder all node QAQ
void getDFS(TreeNode* root, vector<int> &v)
{
	if (root)
	{
		v.push_back(root->val);
		getDFS(root->left, v);
		getDFS(root->right, v);
	}
}

void setDFS(TreeNode* root, vector<int> &v, int i)
{
	if (i > v.size() - 1) return;
	else root->right = new TreeNode(v[i]);

		//root->val = v[i];
		if (root->left) {
			root->left = NULL;
			delete root->left;
		}
		
		setDFS(root->right, v, i + 1);
	
}

TreeNode* increasingBST(TreeNode* root) {
	vector<int> vec;
	getDFS(root, vec);
	sort(vec.begin(), vec.end());
	TreeNode* head = new TreeNode(NULL);
	head->right = root;
	setDFS(head, vec, 0);
	return head->right;
}

#endif

/*

Straigh forward idea:
res = inorder(root.left) + root + inorder(root.right)

Several tips here:

1. I pass a tail part to the function, so it can link it to the last node.
This operation takes O(1), instead of O(N).
Otherwise the whole time complexity will be O(N^2).

2. Also, remember to set root.left = null.
Otherwise it will be TLE for Leetcode to traverse your tree.

3. Should arrange the old tree, not create a new tree.
The judgement won't take it as wrong answer, but it is.
*/
TreeNode* increasingBST(TreeNode* root, TreeNode* tail = NULL) {
	if (!root) return tail;
	TreeNode* res = increasingBST(root->left, root);
	root->left = NULL;
	root->right = increasingBST(root->right, tail);
	return res;
}

class Solution {
	TreeNode *hd = new TreeNode(0);
	TreeNode *p = hd;
public:
	TreeNode* increasingBST(TreeNode* root) {
		if (!root)   return nullptr;
		increasingBST(root->left);
		p->right = new TreeNode(root->val);
		p = p->right;
		increasingBST(root->right);
		return hd->right;
	}
};

class Solution2 {
public:
	TreeNode* increasingBST(TreeNode* root) {
		TreeNode dummy = TreeNode(0);
		TreeNode* pre = &dummy;
		DFSHelper(root, pre);
		return dummy.right;
	}
	void DFSHelper(TreeNode* root, TreeNode*& pre) {
		if (!root) {
			return;
		}
		DFSHelper(root->left, pre);
		pre->right = root;
		root->left = NULL;
		pre = root;
		DFSHelper(root->right, pre);
	}

};

class Solution3 {
public:
	TreeNode* nroot = new TreeNode(0);
	TreeNode* prev = nroot;
	TreeNode* increasingBST(TreeNode* root) {

		helper(root);
		return nroot->right;
	}

	void helper(TreeNode* root)
	{

		if (root == NULL)
			return;

		helper(root->left);
		prev->right = root;
		prev = root;
		prev->left = NULL;
		helper(root->right);

	}

};

int main_897()
{

	TreeNode* node = TreeCreate(13, 5, 3, 6, 2, 4, null, 8, 1, null, null, null, 7, 9);
	TreePrint(node);
	TreeNode* after_node = increasingBST(node);
	TreePrint(after_node);
	getchar();
	return 0;
}

