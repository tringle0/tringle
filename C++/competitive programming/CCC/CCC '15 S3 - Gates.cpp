#include <vector>
#include <iostream>
using namespace std;

//CCC '15 S3 - Gates
//https://dmoj.ca/problem/ccc15s3
//11-13-2025


class gates {
	
public:
	vector<int> nextAvailable;
	gates(int G) {
		for (int k = 0; k < G; k++) {
			nextAvailable.push_back(k);
		}
	}

	bool addPlane(int n) {
		return getNextRec(n) != -1;
	}

	int getNextRec(int n) {
		if (n == -1) return -1;
		if (nextAvailable.at(n) == n) {
			return nextAvailable.at(n)--;
		}
		else {
			nextAvailable.at(n) = getNextRec(nextAvailable.at(n));
			return nextAvailable.at(n);
		}
	}

};

int main() {
	int G; cin >> G; //num of gates
	int P; cin >> P; //num of planes
	
	gates g(G);
	int counter = 0;
	for (int k = 0; k < P; k++) {
		int in; cin >> in;
		if (!g.addPlane(in - 1)) break;
			counter++;
	}
	cout << counter;
}