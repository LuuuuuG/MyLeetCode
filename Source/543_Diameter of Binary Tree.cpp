#include <00_util.h>
#include <algorithm> //std::max

/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
		  1
		 / \
		2   3
	   / \
	  4   5
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.

543. Diameter of Binary Tree: https://leetcode.com/problems/diameter-of-binary-tree/description/
*/

class Solution {
	int maxLen = 0;
public:
	int diameterOfBinaryTree(TreeNode* root)
	{
		depth(root);
		return maxLen;
	}

	int depth(TreeNode* root)
	{
		if (!root) return 0;

		int left = depth(root->left);
		int right = depth(root->right);
		maxLen = max(maxLen, left + right);

		return 1 + max(left, right);
	}
};