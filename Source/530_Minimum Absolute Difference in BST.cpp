#include <algorithm>
#include "000_util.h"


/*

给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。

 

示例：

输入：

   1
    \
     3
    /
   2

输出：
1

解释：
最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。


*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//28ms
class Solution {
public:
	int minVal = INT_MAX;
	int getMinimumDifference(TreeNode* root) {
		helper(root, NULL, NULL);
		return minVal;
	}
	void helper(TreeNode* node, TreeNode* minNode, TreeNode* maxNode)
	{
		if (!node) return;
		if (minNode) minVal = min(minVal, node->val - minNode->val);
		if (maxNode) minVal = min(minVal, maxNode->val - node->val);
		helper(node->left, minNode, node);
		helper(node->right, node, maxNode);
	}
};

class Solution2 {
public:
	int getMinimumDifference(TreeNode* root) {
		int res = INT_MAX, prev = -1;
		dfs(root, prev, res);
		return res;
	}
	void dfs(TreeNode* root, int& prev, int& res)
	{
		if (!root) return;
		dfs(root->left, prev, res);
		if (prev >= 0) res = min(res, root->val - prev);
		prev = root->val;
		dfs(root->right, prev, res);
	}
};