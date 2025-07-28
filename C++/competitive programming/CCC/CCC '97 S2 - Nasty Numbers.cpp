#include <iostream>
#include <unordered_set>
#include <math.h>
using namespace std;

//CCC '97 S2 - Nasty Numbers
//https://dmoj.ca/problem/ccc97s2
//6-19-2025

bool isNasty(int N) {
	unordered_set<int> sums;
	for (int k = 1; k <= N; k++) {
		if (N % k == 0) {
			sums.insert(k + N / k);
			if (sums.count(abs(k - N / k)) > 0) return true;
		}
	}
	return false;
}


int main() {
	int n; cin >> n;
	for (int k = 0; k < n; k++) {
		int in; cin >> in;
		cout << in << (isNasty(in) ? " is nasty" : " is not nasty") << endl;
	}
}