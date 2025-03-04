#include <iostream>
#include <vector>
using namespace std;

//CCC '23 S1 - Trianglane
//https://dmoj.ca/problem/ccc23s1
//1-13-2025

int main() {
	int n; cin >> n;
	vector<int> row1, row2;
	for (int k = 0; k < n; k++) {
		int in; cin >> in; row1.push_back(in);
	}
	for (int k = 0; k < n; k++) {
		int in; cin >> in; row2.push_back(in);
	}
	int sum = 0;
	for (int k = 0; k < n; k++) {
		if (k & 1) {
			//toprow
			if (row1.at(k) == 1) {
				sum += 3;
				if (k>0 && row1.at(k - 1) == 1) sum--;
				if (k<n-1 && row1.at(k + 1) == 1) sum--;
			}
			//bottomrow
			if (row2.at(k) == 1) {
				sum += 3;
				if (k > 0 && row2.at(k - 1) == 1) sum--;
				if (k < n - 1 && row2.at(k + 1) == 1) sum--;
			}
		}
		else {
			//toprow
			if (row1.at(k) == 1) {
				sum += 3;
				if (k > 0 && row1.at(k - 1) == 1) sum--;
				if (k < n - 1 && row1.at(k + 1) == 1) sum--;
				if (row2.at(k) == 1) sum--;
			}
			if (row2.at(k) == 1) {
				sum += 3;
				if (k > 0 &&row2.at(k - 1) == 1) sum--;
				if (k < n - 1 && row2.at(k + 1) == 1) sum--;
				if (row1.at(k) == 1) sum--;
			}
		}
	}
	
	cout << sum;
}