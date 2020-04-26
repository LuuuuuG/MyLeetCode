#include <queue>
#include "000_util.h"

/*

给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]

*/


class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;

		if (root == NULL)   return{};
		queue<TreeNode*> q;
		q.push(root);
		bool leftToRight = true;
		while (!q.empty())
		{
			int count = q.size();             //队列大小表示当前层数的元素个数
			vector<int> level(count);                //存放每一层的元素值
			for (int i = 0; i < count; ++i)                  //count--逐个对该层元素进行处理
			{
				TreeNode *t = q.front();
				q.pop();
				int index = leftToRight ? i : (count - 1 - i);
				level[index] = t->val;
				if (t->left)     q.push(t->left);
				if (t->right)    q.push(t->right);
			}
			leftToRight = !leftToRight;
			res.push_back(level);           //将当层元素的vector加入res中
		}
		return res;
	}
};