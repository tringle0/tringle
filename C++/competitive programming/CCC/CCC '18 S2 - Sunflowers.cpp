#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//CCC '18 S2 - Sunflowers
//https://dmoj.ca/problem/ccc18s2
//7-26-2025

void PrintGrid(vector<vector<int>> grid) {
	for (auto k : grid) {
		for (int i : k) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}

vector<vector<int>> Rotate90(vector<vector<int>> grid) {
	for (int k = 0; k < grid.size(); k++) {
		for (int i = 0; i < k; i++) {
			swap(grid[k][i], grid[i][k]);
		}

	}
	for (int k = 0; k < grid.size(); k++) {
		reverse(grid[k].begin(), grid[k].end());
	}
	return grid;
}


vector<vector<int>> FindRotation(vector<vector<int>> grid) {
	int hDelta = 0, vDelta = 0; //direction of increase
	
	//find deltas
	for (int k = 1; k < grid.size(); k++) {
		for (int i = 1; i < grid.at(k).size(); i++) {
			
			hDelta = grid[k][i] - grid[k][i - 1];
			vDelta = grid[k][i] - grid[k - 1][i];

			if (hDelta != 0 && vDelta != 0) {
				break;
			}
		}
	}

	if (hDelta > 0 && vDelta < 0) {
		//clockwise rotation
		grid = Rotate90(grid);
	}
	if (hDelta < 0 && vDelta < 0) {
		grid = Rotate90(Rotate90(grid));
	}
	if (hDelta < 0 && vDelta > 0) {
		grid = Rotate90(Rotate90(Rotate90(grid)));

	}
	return grid;
}


int main() {
	int n; cin >> n;
	vector<vector<int>> grid(n, vector<int>(n));
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			int input; cin >> input;
			grid[k][i] = input;
		}
	}
	PrintGrid(FindRotation(grid));

}