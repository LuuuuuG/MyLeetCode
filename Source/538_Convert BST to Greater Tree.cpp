#include <00_util.h>

/*
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
			  5
			/   \
		   2     13

Output: The root of a Greater Tree like this:
			 18
			/   \
		  20     13

538. Convert BST to Greater Tree: https://leetcode.com/problems/convert-bst-to-greater-tree/description/
*/

class Solution {
	int sum = 0;
public:
	TreeNode* convertBST(TreeNode* root) {
		if (!root) return NULL;
		root->right = convertBST(root->right);

		root->val += sum;
		sum = root->val;

		root->left = convertBST(root->left);
		return root;
	}
};