#include <iostream>
#include <string>
#include <vector>
using namespace std;

//CCC '10 S1 - Computer Purchase
//https://dmoj.ca/problem/ccc10s1
//2-24-2025

int main() {
	int n; cin >> n;
	struct computer {
		int r = 0, s = 0, d = 0;
		string name;
		int getvalue() {
			return 2 * r + 3 * s + d;
		}
		bool betterthan(computer a) {
			if (this->getvalue() > a.getvalue()) return true;
			if (this->getvalue() == a.getvalue() && this->name.compare(a.name) < 0) return true;
			return false;
		}
	};
	computer best, secondbest;
	for (int k = 0; k < n; k++) {
		computer current;
		cin >> current.name >> current.r >> current.s >> current.d;
		if (current.betterthan(best)) {
			secondbest = best;
			best = current;
		}
		else {
			if (current.betterthan(secondbest)) {
				secondbest = current;
			}
		}
	}
	cout << best.name << endl << secondbest.name;
}