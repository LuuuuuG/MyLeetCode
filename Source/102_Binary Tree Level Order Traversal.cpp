#include <queue>
#include "000_util.h"

/*

给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

 

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]


*/

//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

//DFS
class Solution1 {
public:
	vector<vector<int>> res;
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		addVector(root, 0);      //调用递归函数
		return res;
	}

	void addVector(TreeNode* root, int level)
	{
		if (root == NULL)    return;
		if (res.size() == level)       res.resize(level + 1);    //level表示层数，也对应二维数组的第一层索引，
		res[level].push_back(root->val);
		addVector(root->left, level + 1);
		addVector(root->right, level + 1);
	}
};

//BFS
class Solution2 {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;

		if (root == NULL)   return{};
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			vector<int> level;                //存放每一层的元素值
			int count = q.size();             //队列大小表示当前层数的元素个数
			while (count--)                  //count--逐个对该层元素进行处理
			{
				TreeNode *t = q.front();
				q.pop();
				level.push_back(t->val);
				if (t->left)     q.push(t->left);
				if (t->right)    q.push(t->right);
			}

			res.push_back(level);           //将当层元素的vector加入res中
		}
		return res;
	}
};

#include <stack>
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> result;
	stack<pair<TreeNode*, int> > stk;
	stk.push((make_pair(root, 0)));

	while (!stk.empty()) {
		//auto[node, type] = stk.top();
		TreeNode* node = stk.top().first;
		int type = stk.top().second;
		stk.pop();
		if (node == nullptr) continue;
		if (type == 0) {
			stk.push(make_pair(node->right, 0));
			stk.push(make_pair(node, 1));
			stk.push(make_pair(node->left, 0));
		}
		else result.push_back(node->val);
	}
	return result;
}

int main_102()
{
	TreeNode *tree = TreeCreate(7, 3, 9, 20, INT_MAX, INT_MAX, 15, 7);
	TreePrint(tree);

	Solution1 s2;
	vector<vector<int> > res = s2.levelOrder(tree);
	//Vector2DPrint(res);

	cout << "[" << endl;;
	for (auto vecs : res)
	{
		cout << "[ ";
		for (auto i : vecs)
			cout << i << ", ";
		cout << " ]" << endl;
	}
	cout << "]" << endl;

	system("pause");
	return 0;
}