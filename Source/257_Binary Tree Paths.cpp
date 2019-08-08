#include <000_util.h>
#include <iostream>
#include <string>
using namespace std;

/*

Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

     1
   /   \
  2     3
    \
     5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3

257. Binary Tree Paths: https://leetcode.com/problems/binary-tree-paths/description/
*/

void helper(TreeNode* node, string& s)
{
	if (!node)
	{
		s += "->";
		s += to_string(node->val);
		helper(node->left, s);
		helper(node->right, s);
	}
}

vector<string> binaryTreePaths(TreeNode* root) {
	vector<string> res;
	if (!root) return res;

	string left = to_string(root->val);
	helper(root->left, left);

	string right = to_string(root->val);
	helper(root->right, right);

	res.push_back(left);
	res.push_back(right);

	return res;
}