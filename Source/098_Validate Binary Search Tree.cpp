#include "000_util.h"

/*

给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。

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

//4ms solution:
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return isValidBST(root, NULL, NULL);
	}
	bool isValidBST(TreeNode* node, TreeNode* left, TreeNode* right)
	{
		if (!node) return true;
		if (left && left->val >= node->val || right && right->val <= node->val) return false;
		return isValidBST(node->left, left, node) && isValidBST(node->right, node, right);
	}
};

//12ms solution:
class Solution2 {
public:
	bool isValidBST(TreeNode* root) {
		TreeNode* prev = NULL;
		return validate(root, prev);
	}
	bool validate(TreeNode* node, TreeNode* &prev) {
		if (node == NULL) return true;
		if (!validate(node->left, prev)) return false;
		if (prev != NULL && prev->val >= node->val) return false;
		prev = node;
		return validate(node->right, prev);
	}
};

int main_98()
{
	TreeNode *tree = TreeCreate(3/*node count*/, 2, 1, 3);
	//TreeNode *tree = TreeCreate(7/*node count*/, 5, 1, 4, INT_MAX, INT_MAX, 3, 6);
	TreePrint(tree);

	Solution2 s2;
	bool ret = s2.isValidBST(tree);

	cout << "\n ret = " << ret << endl;

	system("pause");
	return 0;
}