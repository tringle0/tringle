#include <vector>
#include <iostream>
using namespace std;

//CCC '15 S3 - Gates
//https://dmoj.ca/problem/ccc15s3
//8-19-2025

int main() {
	int g; cin >> g;
	vector<bool> gates(g, false);

	int p; cin >> p;
	bool completed = false;
	int counter = 0;
	for (int k = 0; k < p; k++) {
		int plane; cin >> plane;
		counter++; 
		plane--;
		while (gates[plane]) {
			if (plane == 0) {
				completed = true;
				break;
			}
			plane--;
		}
		if (completed) break;
		gates[plane] = true;
	}
	cout << counter;
}