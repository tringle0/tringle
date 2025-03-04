#include <iostream>
#include <vector>

using namespace std;

//CCC '12 S5 - Mouse Journey
//https://dmoj.ca/problem/ccc12s5
//2-18-2025

int main() {

	int r, c;
	cin >> r >> c;
	vector<vector<int>> grid(r, vector<int>(c));

	int n; cin >> n;
	for (int k = 0; k < n; k++) {
		int cr, cc; 
		cin >> cr >> cc;
		grid[--cr][--cc] = -1;
	}
	grid.front().front() = 1;
	for (int k = 0; k < grid.size(); k++) {
		for (int i = 0; i < grid.at(k).size(); i++) {
			if (grid[k][i] == 0) {
				grid[k][i] = (k!=0?grid[k - 1][i]:0) + (i!=0?grid[k][i - 1]:0);
			}
			if (grid[k][i] == -1) { grid[k][i] = 0; continue; }
		}
	}
	cout << grid.back().back();
}