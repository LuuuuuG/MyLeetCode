#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Your KthLargest class will have a constructor which accepts an integer k and an integer array nums, which contains initial elements from the stream. For each call to the method KthLargest.add, return the element representing the kth largest element in the stream.

Example:

int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8
Note:
You may assume that nums' length ¡Ý k-1 and k ¡Ý 1.

703. Kth Largest Element in a Stream: https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
*/

class KthLargest {
public:
	KthLargest(int k, vector<int> nums) : m_k(k) {
		for (auto num : nums) {
			add(num);
		}
	}

	int add(int val) {
		if (q.size() < m_k) {
			q.push(val);
		}
		else if (q.top() < val) {
			q.pop();
			q.push(val);
		}
		return q.top();
	}

private:
	priority_queue<int, vector<int>, greater<int>> q;
	int m_k;
};

void testQueue()
{
	//priority_queue<int> q;//Ä¬ÈÏ´ó¶¥¶Ñ   //9 8 7 6 5 4 3 2 1
	//priority_queue<int, vector<int>, less<int> >q; //´ó¶¥¶Ñ
	priority_queue<int, vector<int>, greater<int> >q;//Ð¡¶¥¶Ñ  //1 2 3 4 5 6 7 8 9

	cout << "\n----------------test----------------------\n" << endl;
	for (int i = 0; i < 10; i++)
		q.push(i);
	while (!q.empty()) {
		cout << q.top() << endl;
		q.pop();
	}
	cout << "\n----------------test----------------------\n" << endl;

}

int main_703()
{
	vector<int> v{ 4,5,8,2 };
	KthLargest kLarg(3, v);
	
	testQueue();

	int res = 0;
	res = kLarg.add(3);
	cout << res << endl;
	res = kLarg.add(5);
	cout << res << endl;
	res = kLarg.add(10);
	cout << res << endl;
	res = kLarg.add(9);
	cout << res << endl;
	res = kLarg.add(4);
	cout << res << endl;

	system("pause");
	return 0;
}