#include "000_util.h"
#include <stack>
/*
����һ���������ĸ��ڵ� root ���������� ���� ����


��ʾ��

���нڵ���Ŀ�ڷ�Χ [0, 100] ��
-100 <= Node.val <= 100


����: �ݹ��㷨�ܼ򵥣������ͨ�������㷨�����

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
		��ɫ��Ƿ�-һ��ͨ���Ҽ���������������:

		���ջ���������ĸ�Ч������ݹ鷽��һ������׶�������Ҫ���ǣ����ַ�������ǰ�����򡢺���������ܹ�д����ȫһ�µĴ��롣

		�����˼�����£�

		ʹ����ɫ��ǽڵ��״̬���½ڵ�Ϊ��ɫ���ѷ��ʵĽڵ�Ϊ��ɫ��
		��������Ľڵ�Ϊ��ɫ��������Ϊ��ɫ��Ȼ�������ӽڵ㡢�������ӽڵ�������ջ��
		��������Ľڵ�Ϊ��ɫ���򽫽ڵ��ֵ�����

		���ߣ�hzhu212
		���ӣ�https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/yan-se-biao-ji-fa-yi-chong-tong-yong-qie-jian-ming/
		��Դ�����ۣ�LeetCode��
		����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
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