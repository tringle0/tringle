#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	int N, D, K, X; cin >> N >> D >> K >> X;
	int counter = 0;
	int cspd;
	vector<double> spds;
	for (int k = 0; k < N; k++) {
		int in; cin >> in; spds.push_back(in);
	}
	double P; cin >> P;
	for (int k = 0; k < N; k++) {
		cspd = spds.at(k);
		while (int(double(D) / double(cspd)) >= int(double(D) / double(P))) {
			counter++;
			if (counter > K) break;
			cspd = int(cspd * double(double(100 - X) / 100.0));
		}
		if (counter > K) break;
	}
	cout << (counter <= K ? "YES" : "NO");
}