#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

/*
Every email consists of a local name and a domain name, separated by the @ sign.

For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.

Besides lowercase letters, these emails may contain '.'s or '+'s.

If you add periods ('.') between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name.  For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.  (Note that this rule does not apply for domain names.)

If you add a plus ('+') in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to my@email.com.  (Again, this rule does not apply for domain names.)

It is possible to use both of these rules at the same time.

Given a list of emails, we send one email to each address in the list.  How many different addresses actually receive mails?



Example 1:

Input: ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails


Note:

1 <= emails[i].length <= 100
1 <= emails.length <= 100
Each emails[i] contains exactly one '@' character.

929. Unique Email Addresses: https://leetcode.com/problems/unique-email-addresses/description/
*/
class Solution{
	//32ms solution:
	string emailHelper(string email)
	{
		string res;
		bool skip_all = true;
		bool skip_plus = false;
		for (auto i : email)
		{
			if (i == '@')
			{
				skip_all = false;
				skip_plus = false;
			}
			if (i == '+')
			{
				skip_plus = true;
			}
			if ((i == '.' || skip_plus) && skip_all)
				continue;
			else
				res.push_back(i);
		}
		return res;
	}

	int numUniqueEmails(vector<string>& emails) {
		set<string> s;
		for (auto i : emails)
			s.insert(emailHelper(i));
		return s.size();
	}
};

class Solution2{
public:
	static int numUniqueEmails(vector<string>& emails) {
		//process strings and insert them into a set, then return the size of the set

		if (emails.empty()) {
			return 0;
		}

		unordered_set<string> S;
		//for each email address, build a processed string
		for (string& str : emails) {
			int i = 0;
			bool domain = false;
			string buffer = "";
			// check each character in email address
			while (i < str.length()){
				// if it's '+', go until '@'
				if (!domain && str[i] == '+') {
					while (str[i] != '@') {
						i++;
					}
				}

				// if it's '@', it's domain
				if (str[i] == '@') {
					domain = true;
				}

				// if it's not domain, ignore '.'
				if (domain || str[i] != '.') {
					buffer += str[i];
				}
				i++;
			}
			// insert to the set
			S.insert(buffer);
		}
		return S.size();
	}
};

int main_929()
{
	vector<string> emails{ "test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com" };
	int res = Solution2::numUniqueEmails(emails);
	cout << res << endl;

	system("pause");
	return 0;
}
