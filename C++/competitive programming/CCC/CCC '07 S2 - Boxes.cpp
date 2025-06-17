#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
using namespace std;

//CCC '07 S2 - Boxes
//https://dmoj.ca/problem/ccc07s2
//6-16-2025


struct cuboid {
public:
	int x = 0, y = 0, z = 0;
	int getVolume() {
		return x * y * z;
	}
	void rotate() {
		int temp = x;
		x = y;
		y = z;
		z = temp;
	}
	void flip() {
		int temp = z;
		z = x;
		x = temp;
	}
	bool fitsInside(cuboid b) {
		return x <= b.x && y <= b.y && z <= b.z;
	}
};

class cuboidChecker {
public:
	vector<cuboid> containers;
	cuboidChecker(vector<cuboid> c) {
		containers = c;
	}

	int checkcuboid(cuboid b) {
		long int smallest = LONG_MAX;
		int found = false;
		for (cuboid c : containers) {
			if (b.getVolume() > c.getVolume()) continue;
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 3; k++) {
					if (b.fitsInside(c)) {
						smallest = min(smallest, (long)c.getVolume());
						found = true;
						break;
					}
					b.rotate();
				}
				b.flip();
			}
			
		}
		return found?smallest:-1;
	}
};


int main() {
	int n; cin >> n;
	vector<cuboid> boxes;
	for (int k = 0; k < n; k++) {
		int x, y, z; cin >> x >> y >> z; //dimensions
		boxes.push_back({ x, y, z });
	}
	cuboidChecker checker(boxes);
	cin >> n;
	for (int k = 0; k < n; k++) {
		int x, y, z; cin >> x >> y >> z; //dimensions
		int result = checker.checkcuboid({ x,y,z });
		if (result == -1) {
			cout << "Item does not fit.";
		}
		else {
			cout << result;
		}
		cout << endl;
	}
}