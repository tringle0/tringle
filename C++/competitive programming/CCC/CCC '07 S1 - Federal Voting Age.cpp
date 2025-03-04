#include <iostream>
using namespace std;

//CCC '07 S1 - Federal Voting Age
//https://dmoj.ca/problem/ccc07s1
//2-28-2025

bool isValid(int y, int m, int d) {
	if (y < 1989) return true;
	if (y == 1989 && m < 2) return true;
	if (y == 1989 && m == 2 && d <= 27) return true;
	return false;
}

int main() {
	int n; cin >> n;
	for (int k = 0; k < n; k++) {
		int y, m, d;
		cin >> y >> m >> d;
		cout << (isValid(y, m, d) ? "Yes" : "No") << endl;

	}
}