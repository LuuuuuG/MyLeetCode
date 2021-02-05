#include "000_util.h"

/*
96. ��ͬ�Ķ���������

����һ������ n������?1 ...?n?Ϊ�ڵ���ɵĶ����������ж����֣�

ʾ��:

����: 3
���: 5
����:
���� n = 3, һ���� 5 �ֲ�ͬ�ṹ�Ķ���������:

1         3     3      2      1
\       /     /      / \      \
3     2     1      1   3      2
/     /       \                 \
2     1         2                 3

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/unique-binary-search-trees
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

*/



/*
����˼·
��ǩ����̬�滮
���� n ���ڵ���ڶ����������ĸ����� G (n)���� f(i) Ϊ�� i Ϊ���Ķ����������ĸ�������
G(n) = f(1) + f(2) + f(3) + f(4) + ... + f(n)G(n)=f(1)+f(2)+f(3)+f(4)+...+f(n)

�� i Ϊ���ڵ�ʱ�����������ڵ����Ϊ i-1 �����������ڵ�Ϊ n-i����
f(i) = G(i-1)*G(n-i)f(i)=G(i?1)?G(n?i)

�ۺ�������ʽ���Եõ� �������� ��ʽ
G(n) = G(0)*G(n-1)+G(1)*(n-2)+...+G(n-1)*G(0)G(n)=G(0)?G(n?1)+G(1)?(n?2)+...+G(n?1)?G(0)

���ߣ�guanpengchn
���ӣ�https://leetcode-cn.com/problems/unique-binary-search-trees/solution/hua-jie-suan-fa-96-bu-tong-de-er-cha-sou-suo-shu-b/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������

��������:
https://baike.baidu.com/item/%E5%8D%A1%E7%89%B9%E5%85%B0%E6%95%B0
1) �����ڵ���ɶ���������
2��n��������ȷƥ����Ŀ
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