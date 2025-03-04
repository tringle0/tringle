#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
	int n; cin >> n; 
	for (int k = 0; k < n; k++) {
		string in; cin >> in; in += "a";
		string out = "";
		string num = "";
		int sum = 0;
		int c = 0;
		for (int c = 0; c < in.length(); c++) {	
			if (in.at(c) >= 'A' && in.at(c) <= 'Z') {
				out += in.at(c);
			}
			if (in.at(c) == '-' || (in.at(c) >= '0' && in.at(c) <= '9')) {
				num = "";
				bool neg = false;
				if (in.at(c) == '-') {
					c++;
					neg = true;
				}
				while (in.at(c) >= '0' && in.at(c) <= '9') {
					num += in.at(c);
					c++;
				}
				sum += (neg?-1:1) * stoi(num);
				c--;
			}

		}
		cout << out << sum << endl;
	}
}