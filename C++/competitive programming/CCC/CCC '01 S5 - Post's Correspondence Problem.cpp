#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool minStringsEqual(string a, string b) {
	int minL = min(a.length(), b.length());
	return a.substr(0,minL) == b.substr(0,minL);
}
string findString(string sa, string sb, vector<string> &a, vector<string> &b, string nums, int &n, int &m) {
	if (!minStringsEqual(sa, sb) && sa != "") return "no";
	if (nums.length() >= m) return "no";
	if (sa == sb && sa != "") return nums;
	for (int k = 0; k < n; k++) {
		string result = findString(sa + a.at(k), sb + b.at(k), a, b, nums + to_string(k + 1), n, m);
		if (result != "no") return result;
	}
	return "no";
}

int main() {
	int m, n;
	cin >> m >> n;

	vector<string> a;
	vector<string> b;

	for (int k = 0; k < n; k++) {
		string in; cin >> in;
		a.push_back(in);
	}
	for (int k = 0; k < n; k++) {
		string in; cin >> in;
		b.push_back(in);
	}

	string ans = findString("", "", a, b, "", n, m);
	if (ans == "no") cout << "No solution.";
	else {
		cout << ans.length() << endl;
		for (char c : ans) {
			cout << c << endl;
		}
	}
	
}