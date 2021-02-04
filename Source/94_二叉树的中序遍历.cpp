#include "000_util.h"
#include <stack>
/*
给定一个二叉树的根节点 root ，返回它的 中序 遍历


提示：

树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100


进阶: 递归算法很简单，你可以通过迭代算法完成吗？

*/

class Solution {
public:
	vector<int> res;
	vector<int> inorderTraversal(TreeNode* root) {
		//DFS(root, 0);
		BFS(root);
		return res;
	}

	void DFS(TreeNode* root, int level)
	{
		if (!root) return;

		DFS(root->left, level + 1);
		res.push_back(root->val);
		DFS(root->right, level + 1);
	}
	/*
		颜色标记法-一种通用且简明的树遍历方法:

		兼具栈迭代方法的高效，又像递归方法一样简洁易懂，更重要的是，这种方法对于前序、中序、后序遍历，能够写出完全一致的代码。

		其核心思想如下：

		使用颜色标记节点的状态，新节点为白色，已访问的节点为灰色。
		如果遇到的节点为白色，则将其标记为灰色，然后将其右子节点、自身、左子节点依次入栈。
		如果遇到的节点为灰色，则将节点的值输出。

		作者：hzhu212
		链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/yan-se-biao-ji-fa-yi-chong-tong-yong-qie-jian-ming/
		来源：力扣（LeetCode）
		著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
	*/
	void BFS(TreeNode* root)
	{
		stack<pair<TreeNode*, int> > stk;
		stk.push((make_pair(root, 0)));
		while (!stk.empty())
		{
			TreeNode* node = stk.top().first;
			int type = stk.top().second;
			stk.pop();
			if (!node) continue;
			if (type == 0)
			{
				stk.push(make_pair(node->right, 0));
				stk.push(make_pair(node, 1));
				stk.push(make_pair(node->left, 0));
			}
			else
				res.push_back(node->val);
		}
	}
};