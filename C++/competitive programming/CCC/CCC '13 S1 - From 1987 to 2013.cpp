#include <iostream>
#include <unordered_set>
#include <math.h>
using namespace std;

//CCC '13 S1 - From 1987 to 2013
//https://dmoj.ca/problem/ccc13s1
//2-24-2025

bool isDistinct(int n) {
	unordered_set<int> found;
	for (int k = 0; k < log10(n); k++) {
		int currentdigit = n % (int)pow(10, k + 1) / (pow(10, k + 1) / 10);
		if (found.count(currentdigit) > 0) return false;
		found.insert(currentdigit);	
	}
	return true;
}

int main() {
	int n; cin >> n; n++;
	while (!isDistinct(n++));
	cout << n-1;
}