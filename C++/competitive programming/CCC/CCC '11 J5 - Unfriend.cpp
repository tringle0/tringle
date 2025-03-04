#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//CCC '11 J5 - Unfriend
//https://dmoj.ca/problem/ccc11j5
//2-12-2025

int DFS(vector<vector<int>> people, int current) {
	if (people.at(current).empty()) return 2;
	int product = 1;
	for (int k : people.at(current)) {
		product *= DFS(people, k);
	}
	return product+1;
}

int main() {
	int n; cin >> n;
	vector<vector<int>> people(n);
	for (int k = 0; k < n-1; k++) {
		int input; cin >> input;
		people[input-1].push_back(k);
	}
	cout << DFS(people, n - 1) - 1;
}