#include "000_util.h"

/*
96. 不同的二叉搜索树

给定一个整数 n，求以?1 ...?n?为节点组成的二叉搜索树有多少种？

示例:

输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

1         3     3      2      1
\       /     /      / \      \
3     2     1      1   3      2
/     /       \                 \
2     1         2                 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-binary-search-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/



/*
解题思路
标签：动态规划
假设 n 个节点存在二叉排序树的个数是 G (n)，令 f(i) 为以 i 为根的二叉搜索树的个数，则
G(n) = f(1) + f(2) + f(3) + f(4) + ... + f(n)G(n)=f(1)+f(2)+f(3)+f(4)+...+f(n)

当 i 为根节点时，其左子树节点个数为 i-1 个，右子树节点为 n-i，则
f(i) = G(i-1)*G(n-i)f(i)=G(i?1)?G(n?i)

综合两个公式可以得到 卡特兰数 公式
G(n) = G(0)*G(n-1)+G(1)*(n-2)+...+G(n-1)*G(0)G(n)=G(0)?G(n?1)+G(1)?(n?2)+...+G(n?1)?G(0)

作者：guanpengchn
链接：https://leetcode-cn.com/problems/unique-binary-search-trees/solution/hua-jie-suan-fa-96-bu-tong-de-er-cha-sou-suo-shu-b/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

卡特兰数:
https://baike.baidu.com/item/%E5%8D%A1%E7%89%B9%E5%85%B0%E6%95%B0
1) 给定节点组成二叉搜索树
2）n对括号正确匹配数目
*/
class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;

		for (int i = 2; i <= n; ++i)
		{
			for (int j = 1; j <= i; ++j)
				dp[i] += dp[j - 1] * dp[i - j];
		}

		return dp[n];
	}
};