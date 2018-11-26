#include <iostream>
#include <stack>
using namespace std;

/*
Invert a binary tree.

Example:

Input:
      4
    /   \
  2     7
 / \   / \
1   3 6   9

Output:
       4
     /   \
   7     2
  / \   / \
 9   6 3   1

226. Invert Binary Tree: https://leetcode.com/problems/invert-binary-tree/description/
*/

/*
* Definition for a binary tree node.
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Recursion
TreeNode* invertTree(TreeNode* root) {
	if (root == NULL) return NULL;
	invertTree(root->left);
	invertTree(root->right);
	swap(root->left, root->right);
	return root;
}

//no-Recursion
TreeNode* invertTree2(TreeNode* root) {
	std::stack<TreeNode*> stk;
	stk.push(root);

	while (!stk.empty()) {
		TreeNode* p = stk.top();
		stk.pop();
		if (p) {
			stk.push(p->left);
			stk.push(p->right);
			std::swap(p->left, p->right);
		}
	}
	return root;
}
