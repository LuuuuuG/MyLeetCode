#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

121. Best Time to Buy and Sell Stock: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
*/

// 1388 ms QAQ
int maxProfit(vector<int>& prices) {
	int res = 0;
	for (int i = 0; i < prices.size(); ++i)
		for (int j = i + 1; j < prices.size(); ++j)
			res = max(prices[j] - prices[i], res);
	return res;
}

//compare and find out minimum price to buy.
int maxProfit2(vector<int> &prices) {
	int maxPro = 0;
	int minPrice = INT_MAX;
	for (int i = 0; i < prices.size(); i++){
		minPrice = min(minPrice, prices[i]);
		maxPro = max(maxPro, prices[i] - minPrice);
	}
	return maxPro;
}

int main_121()
{
	vector<int> v = { 7, 1, 5, 3, 6, 4 };
	int res = maxProfit(v);
	cout << "res = " << res << endl;

	system("pause");
	return 0;
}