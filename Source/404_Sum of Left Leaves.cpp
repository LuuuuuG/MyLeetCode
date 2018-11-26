#include <iostream>
using namespace std;

/*

Find the sum of all left leaves in a given binary tree.

Example:

     3
    / \
   9  20
  /  \
15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

404. Sum of Left Leaves: https://leetcode.com/problems/sum-of-left-leaves/description/
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

int sumOfLeftLeaves(TreeNode* root, bool isleft = false)
{
	if (root == NULL) return 0;
	int ans = 0;
	if (root->left)
	{
		if (root->left->left == NULL && root->left->right == NULL)
			ans += root->left->val;
		else
			ans += sumOfLeftLeaves(root->left);
	}
	ans += sumOfLeftLeaves(root->right);
	return ans;
}


//using default argument:
int sumOfLeftLeaves2(TreeNode* root, bool isleft = false) {
	if (!root) return 0;
	if (!root->left && !root->right) return isleft ? root->val : 0;
	return sumOfLeftLeaves2(root->left, true) + sumOfLeftLeaves2(root->right, false);
}

//0 ms solution:
class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == NULL) return sum;
		helper(root, 0);
		return sum;
	}
	void helper(TreeNode* node, int mode) {
		if (node->left == NULL && node->right == NULL) {
			if (mode == 1) sum += node->val;
			return;
		}
		if (node->left) helper(node->left, 1);
		if (node->right) helper(node->right, 2);
	}
private:
	int sum{ 0 };
};