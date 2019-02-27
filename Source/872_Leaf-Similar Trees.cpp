#include <iostream>
#include <vector>
#include <stack>
#include "000_util.h"
using namespace std;

/*

Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.
               3
            /     \
          5          1
       /    \       /   \
     6      2     9      8
           /   \
         7      4

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.



Note:

Both of the given trees will have between 1 and 100 nodes.

872. Leaf-Similar Trees: https://leetcode.com/problems/leaf-similar-trees/description/
*/

//using vector:
class Solution1 {
public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> leaves1;
		vector<int> leaves2;
		dfs(root1, leaves1);
		dfs(root2, leaves2);

		return leaves1 == leaves2;
	}

	void dfs(TreeNode* node, vector<int>& leaves) {
		if (node == NULL) return;
		if (node->left == NULL && node->right == NULL)
			leaves.push_back(node->val);
		dfs(node->left, leaves);
		dfs(node->right, leaves);
	}
};

//using stack: (FILO)
class Solution2 {
public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		stack<TreeNode*> s1, s2;
		s1.push(root1); s2.push(root2);
		while (!s1.empty() && !s2.empty())
		if (dfs(s1) != dfs(s2)) return false;
		return s1.empty() && s2.empty();
	}

	int dfs(stack<TreeNode*>& s) {
		while (true) {
			TreeNode* node = s.top(); s.pop();
			if (node->right) s.push(node->right);
			if (node->left) s.push(node->left);
			if (!node->left && !node->right) return node->val;
		}
	}
};