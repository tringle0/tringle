#include <iostream>
#include <vector>
using namespace std;

//CCC '24 S1 - Hat Circle
//https://dmoj.ca/problem/ccc24s1
//2-20-2025

int main() {
	int n; cin >> n;
	vector<int> circle;
	int counter = 0;
	for (int k = 0; k < n; k++) {
		int input; cin >> input;
		circle.push_back(input);
		if (k >= n / 2) {
			if (circle.at(k - n / 2) == circle.at(k)) counter+=2;
		}
	}
	cout << counter;
}