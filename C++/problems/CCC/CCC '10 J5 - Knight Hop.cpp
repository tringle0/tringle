#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;

//CCC '10 J5 - Knight Hop
//https://dmoj.ca/problem/ccc10j5
//1-14-2025

//using bfs
int main() {
	int x, y, tx, ty; cin >> x >> y >> tx >> ty;
	queue<pair<int, int>> traverse;
	queue<pair<int, int>> nextlevel;
	vector<pair<int, int>> directions = {
		{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}
	};
	unordered_set<int> marked;

	traverse.push({ x,y });
	int counter = 0;
	while (!traverse.empty() || !nextlevel.empty()) {
		int cx = traverse.front().first;
		int cy = traverse.front().second;
		if (cx == tx && cy == ty) break;

		if (marked.count((cx * 10) + cy) == 0) {
			//add neighboors
			for (int k = 0; k < 8; k++) {
				int nx = cx + directions.at(k).first;
				int ny = cy + directions.at(k).second;
				//boundaries
				if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8) {
					nextlevel.push({ nx,ny });
				}
			}
		}
		marked.insert((cx * 10) + cy);
		traverse.pop();

		if (traverse.empty()) {
			while (!nextlevel.empty()) {
				traverse.push(nextlevel.front());
				nextlevel.pop();
			}
			counter++;
		}

	}
	cout << counter;
}