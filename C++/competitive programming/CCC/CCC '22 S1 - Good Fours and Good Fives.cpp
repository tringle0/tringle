#include <iostream>
using namespace std;

//CCC '22 S1 - Good Fours and Good Fives
//https://dmoj.ca/problem/ccc22s1
//3-24-2025

int main() {
	int n; cin >> n;
	int ans = 0;
	for (int k = 0; k * 5 <= n; k++) {
		if ((n - k * 5) % 4 == 0) ans++;
	}
	cout << ans;
}