#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int numSlices(vector<int> logs, int sliceLength) {
	int sum = 0;
	for (int k : logs) {
		sum += k / sliceLength;
	}
	return sum;
}

int BSSlices(int lb, int tb, int current, int &target, vector<int> &logs) {
	int range = tb - lb;
	if (numSlices(logs, current) > target) {
		tb = lb + range / 2;
	}
	else {
		lb = tb - range / 2;
	}
}

int main() {
	int numLogs, numPieces;
	cin >> numLogs;
	cin >> numPieces;

	
}