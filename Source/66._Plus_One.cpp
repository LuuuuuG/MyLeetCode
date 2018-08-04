#include <iostream>
#include <vector>
using namespace std;


//will overflow when cector size > 8 ?
vector<int> plusOne_my(vector<int>& digits) {
	vector<int> res;
	long long sum = 0;
	int cnt = digits.size() - 1;
	for (auto i : digits)
	{
		sum += i * pow(10, cnt);
		cnt--;
	}
	sum++;
	for (; sum != 0; sum /= 10)
		res.insert(res.begin(), sum % 10);
	return res;
}

//genius solution!!
void plusOne(vector<int>& digits) {
	int n = digits.size();
	for (int i = n - 1; i >= 0; --i)
	{
		if (digits[i] == 9)
		{
			digits[i] = 0;
		}
		else
		{
			digits[i]++;
			return ;
		}
	}
	//digits[0] = 1;
	//digits.push_back(0);
	digits.insert(digits.begin(), 1);
}

int main_66()
{
	vector<int> v = { 9, 9, 9, 9 };
	plusOne(v);

	cout << "v = ";
	for (auto i : v)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}