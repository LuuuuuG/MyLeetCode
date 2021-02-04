#include "000_util.h"
/*

����һ���������� ��������� ������������ʹ��������ߵĽ�����������ĸ�������ÿ�����û�����ӽ�㣬ֻ��һ�����ӽ�㡣

?

 ʾ�� ��

 ���룺[5,3,6,2,4,null,8,1,null,null,null,7,9]

 5
 / \
 3    6
 / \    \
 2   4    8
 ?/        / \
  1        7   9

  �����[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

  1
  ? \
	?  2
	   ? \
		   3
			 \
			  4
				 \
				  5
				   \
					6
					 \
					  7
						\
						 8
							\
							 9
																																		 ?
��ʾ��

�������еĽ�������� 1 ��?100 ֮�䡣
ÿ����㶼��һ���� 0 �� 1000 ��Χ�ڵ�Ψһ����ֵ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/increasing-order-search-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


*/

class Solution {
public:

	void inOrder(TreeNode* root, vector<int> &res)
	{
		if (root == NULL)  return;
		inOrder(root->left, res);
		res.push_back(root->val);
		inOrder(root->right, res);
	}

	TreeNode* increasingBST(TreeNode* root)
	{
		vector<int> res;
		inOrder(root, res);
		TreeNode* ans = new TreeNode(0);
		TreeNode* cur = ans;
		for (auto it : res)
		{
			cur->right = new TreeNode(it);
			cur = cur->right;
		}
		return ans->right;
	}

};