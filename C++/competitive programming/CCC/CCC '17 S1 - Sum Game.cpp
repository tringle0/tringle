#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//CCC '17 S1 - Sum Game
//https://dmoj.ca/problem/ccc17s1
//2-17-2026

int main() {
	int N;
	cin >> N;

	
	vector<int> a, b;
	int sA = 0, sB = 0;
	int input;
	int m = -1;

	for (int k = 0; k < N; k++) { cin >> input; a.push_back(input); }
	for (int k = 0; k < N; k++) { cin >> input; b.push_back(input); }
	for (int k = 0; k < N; k++) {
		sA += a.at(k);
		sB += b.at(k);
		if (sA == sB) m = max(m, k);
	}
	if (m == -1 || m == N) cout << 0;
	else cout << m + 1;
}