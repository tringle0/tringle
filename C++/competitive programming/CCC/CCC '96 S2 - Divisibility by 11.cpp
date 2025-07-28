#include <iostream>
#include <vector>
using namespace std;

//CCC '96 S2 - Divisibility by 11
//https://dmoj.ca/problem/ccc96s2
//6-18-2025


struct bigNumber {
	vector<int> digits;
	string orig;
	bigNumber(string s) {
		for (char c : s) {
			digits.push_back(c - '0');
		}
		orig = s;
	}
	void removeLeadingZeroes() {
		for (int k = 0; k < digits.size();) {
			if (digits.at(k) != 0) break;
			if (digits.empty()) break;
			digits.erase(digits.begin());
		}
	}
	void print() {
		for (int k : digits) {
			cout << k;
		}
		cout << endl;
	}
	void shorten() {
		
		int sub = digits.back();
		digits.erase(digits.end()-1);
		if (digits.back() < sub) {
			sub -= digits.back();
			digits.back() = 10;
			int carryOffset = 2;
			while (digits.at(digits.size() - carryOffset) == 0) {
				digits.at(digits.size() - carryOffset) = 9;
				carryOffset++;
			}
			digits.at(digits.size() - carryOffset)--;
		}
		digits.back() -= sub;
		removeLeadingZeroes();
	}
	bool finished() {
		return digits.size() <= 2;
	}
	bool isEleven() {
		if (digits.size() >= 2)
			return finished() && digits.at(0) == digits.at(1);
		else return false;
	}
};

int main() {
	int n; cin >> n;
	for (int k = 0; k < n; k++) {
		string in; cin >> in;
		bigNumber num(in);
		num.print();
		while (!num.finished()) {
			num.shorten();
			num.print();
		}
		if (num.isEleven()) {
			cout << "The number " + num.orig + " is divisible by 11.\n";
		}
		else {
			cout << "The number " + num.orig + " is not divisible by 11.\n";
		}
		if (k < n - 1) cout << "\n";
	}
}