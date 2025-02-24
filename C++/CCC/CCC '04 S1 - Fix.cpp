#include <iostream>
#include <string>
using namespace std;

//CCC '04 S1 - Fix
//https://dmoj.ca/problem/ccc04s1
//2-24-2025

bool samefix(string a, string b) {
	int shorter = min(a.length(), b.length());
	if (a.substr(0, shorter) == b.substr(0, shorter)) return true;
	if (a.substr(a.length()-shorter, shorter) == b.substr(b.length() - shorter, shorter)) return true;
	return false;
}

int main() {
	int n; cin >> n;
	for (int k = 0; k < n; k++) {
		string a, b, c; cin >> a >> b >> c;
		cout << ((samefix(a, b) || samefix(b, c) || samefix(a, c)) ? "No" : "Yes") << endl;
	}
}