#include<iostream>
#include <vector>
#include <queue>
using namespace std;

//CCC '20 S2 - Escape Room
//https://dmoj.ca/problem/ccc20s2
//2-18-2025

int main() {
	int r, c; cin >> r >> c;
	vector<vector<int>> grid(r, vector<int>(c));
	for (int k = 0; k < r; k++) {
		for (int i = 0; i < c; i++) {
			cin >> grid[k][i];
		}
	}
	struct tile {
		int r, c;
	};
	queue<tile> bfs;
	bfs.push({0, 0});
	
	while (true) {
		if (bfs.empty()) { cout << "no"; break; };
		tile current = bfs.front();
		bfs.pop();
		if (current.r >= r || current.c >= c) continue;
		if (current.r == r - 1 && current.c == c - 1) { cout << "yes"; break; }
		if(grid[current.r][current.c] == -1) continue;
		int val = grid[current.r][current.c];
		grid[current.r][current.c] = -1;
		for (int k = 1; k*k <= val; k++) {
			if (val % k == 0) {
					bfs.push({ k-1, val / k-1});
					bfs.push({val / k - 1, k-1});
			}
		}
	}
}