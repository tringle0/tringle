#include <iostream>
#include <math.h>
using namespace std;

//CCC '05 S2 - Mouse Move
//https://dmoj.ca/problem/ccc05s2
//1-13-2025

int main() {
	int x = 0, y = 0;
	int w, h;
	cin >> w >> h;
	while (true) {
		int ix, iy; cin >> ix >> iy;
		if (ix == 0 && iy == 0) break;
		x += ix;
		y += iy;
		x = max(0, x);
		x = min(w, x);
		y = max(0, y);
		y = min(h, y);
		cout << x << " " << y << endl;
	}
	
}