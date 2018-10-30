#include <iostream>
#include <algorithm>
using namespace std;

/*

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

		3
	   / \
	 9  20
		/  \
	  15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

		1
	   / \
	  2   2
	 / \
	3   3
   / \
 4   4
Return false.

110. Balanced Binary Tree: https://leetcode.com/problems/balanced-binary-tree/description/
*/

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int dfsHeight(TreeNode *root) {
		if (root == NULL) return 0;

		int leftHeight = dfsHeight(root->left);
		if (leftHeight == -1) return -1;
		int rightHeight = dfsHeight(root->right);
		if (rightHeight == -1) return -1;

		if (abs(leftHeight - rightHeight) > 1)  return -1;
		return max(leftHeight, rightHeight) + 1;
	}
	bool isBalanced(TreeNode *root) {
		return dfsHeight(root) != -1;
	}
};


class solution2 {
public:
	int depth(TreeNode *root) {
		if (root == NULL) return 0;
		return max(depth(root->left), depth(root->right)) + 1;
	}

	bool isBalanced(TreeNode *root) {
		if (root == NULL) return true;

		int left = depth(root->left);
		int right = depth(root->right);

		return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
	}
};