#include <iostream>
#include <math.h>
using namespace std;

//CCC '08 S2 - Pennies in the Ring
//https://dmoj.ca/problem/ccc08s2
//7-28-2025

int main() {
	while (true) {
		int radius; cin >> radius;
		if (radius == 0) break;
		int ans = 2 * radius + 1;
		for (int k = -radius; k <= radius; k++) {
			ans += 2*(int)sqrt(radius * radius - k * k);
		}
		cout << ans << endl;
	}
}