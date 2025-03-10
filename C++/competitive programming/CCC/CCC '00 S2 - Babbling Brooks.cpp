#include <iostream>
#include <vector>
using namespace std;

//CCC '00 S2 - Babbling Brooks
//https://dmoj.ca/problem/ccc00s2
//3-9-2025

int main() {
	int n; cin >> n;
	int input; 
	vector<double> streams;
	for (int k = 0; k < n; k++) {
		cin >> input; streams.push_back(input);
	}

	while (true) {
		cin >> input;
		if (input == 99) {
			double stream, split;
			cin >> stream >> split;
			double currstream = streams.at(stream-1);
			streams.insert(streams.begin() + stream, currstream * (100 - split) / 100);
			streams.at(stream-1) = currstream * split / 100;
		}
		if (input == 88) {
			int merge;
			cin >> merge; merge--;
			streams.at(merge) += streams.at(merge + 1);
			streams.erase(streams.begin() + merge + 1);
		}
		if (input == 77) break;
	}

	for (int k : streams) {
		cout << k << " ";
	}
}