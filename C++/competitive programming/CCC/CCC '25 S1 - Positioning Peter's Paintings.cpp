#include <iostream>
using namespace std;

//CCC '25 S1 - Positioning Peter's Paintings
//https://dmoj.ca/problem/ccc25s1
//3-24-2025

int main() {
	int p1w, p1h, p2w, p2h;
	cin >> p1w >> p1h >> p2w >> p2h;

	int alignVertical = 2*max(p1w, p2w) + 2*(p1h + p2h);
	int alignHorizontal = 2*max(p1h, p2h) + 2*(p1w + p2w);

	cout << min(alignVertical, alignHorizontal);
}