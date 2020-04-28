#include <iostream>
#include <algorithm>
#include <queue>
#include "000_util.h"
using namespace std;

/*

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
return its bottom-up level order traversal as:
[
[15,7],
[9,20],
[3]
]


107. Binary Tree Level Order Traversal II: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
*/

//use DFS to implement this.
class Solution1{
public:
	void levelOrder(TreeNode* root, vector<vector<int> > &v, int currLevel) {
		if (root == NULL) {
			return;
		}

		if (v.empty() || currLevel > (v.size() - 1)) {
			v.push_back(vector<int>());	//v.push_back({});
		}
		v[currLevel].push_back(root->val);
		levelOrder(root->left, v, currLevel + 1);
		levelOrder(root->right, v, currLevel + 1);
	}

	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int> > retVal;

		levelOrder(root, retVal, 0);
		reverse(retVal.begin(), retVal.end());
		return retVal;
	}
};

//4ms solution:
class Solution2{
public:
	int depth(TreeNode *root) {
		if (!root) return 0;
		return max(depth(root->left), depth(root->right)) + 1;
	}

	void levelOrder(vector<vector<int>> &ans, TreeNode *node, int level) {
		if (!node) return;
		ans[level].push_back(node->val);
		levelOrder(ans, node->left, level - 1);
		levelOrder(ans, node->right, level - 1);
	}

	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		int d = depth(root);
		vector<vector<int>> ans(d, vector<int> {});
		levelOrder(ans, root, d - 1);
		return ans;
	}
};

//4ms BFS
class Solution3 {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			vector<int> leves;
			int count = q.size();
			while (count--)
			{
				TreeNode* node = q.front();
				q.pop();
				leves.push_back(node->val);

				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

template<typename T>
void myVectorPrint(const vector<T> &vec)
{
	for (auto i : vec)
		cout << i << " ";
	cout << endl;
}

int main_107()
{
	vector<int> v = { 1, 1, 2, 3, 5, 8 };
	//VectorPrint(v);
	ListNode *node = ListCreate(5, 1, 2, 3, 4, 5);
	ListPrint(node);
	TreeNode *tree = TreeCreate(7, 1, 2, 3, 4, 5, 6, 7);
	TreePrint(tree);
	system("pause");
	return 0;
}