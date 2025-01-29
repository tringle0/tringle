#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Mock CCC '14 J5 - Spacetime Surfer
//https://dmoj.ca/problem/mockccc14j5
//2025-01-28

struct tile {
	int r, c, t;
	int distance;
	char id;
};

class Maze {
public:
	vector<vector<vector<tile>>> grid;
	int rows, cols, times;
	tile startpos;
	Maze(vector<vector<vector<tile>>> g, tile start) {
		grid = g;
		times = grid.size();
		rows = grid.at(0).size();
		cols = grid.at(0).at(0).size();
		startpos = start;
	}

	int BFSTraverse() {
		queue<tile> bfs;
		bfs.push(startpos);
		tile current;
		while (true) {
			if (bfs.empty()) return -1;
			current = bfs.front();
			if (current.r >= 0 && current.r < rows && current.c >= 0 && current.c < cols) {
				if (grid[current.t][current.r][current.c].id == 'B') return current.distance;
				
				if (grid[current.t][current.r][current.c].id != 'X') {
					//add neighbors
					bfs.push({ current.r + 1, current.c, current.t,current.distance + 1 });
					bfs.push({ current.r - 1, current.c, current.t,current.distance + 1 });
					bfs.push({ current.r, current.c + 1, current.t,current.distance + 1 });
					bfs.push({ current.r, current.c - 1, current.t,current.distance + 1 });
					for (int k = 0; k < times; k++) {
						if (k != current.t) {
							bfs.push({ current.r,current.c,k,current.distance + 1 });
						}
					}
				}
				grid[current.t][current.r][current.c].id = 'X';
			}
			bfs.pop();
			
		}
	}
};

int main() {
	int r, c, t;
	cin >> r >> c >> t;
	string input;
	vector<vector<vector<tile>>> in;
	tile start = {};
	for (int k = 0; k < t; k++) {
		in.push_back({});
		for (int i = 0; i < r; i++) {
			cin >> input;
			in.at(k).push_back({});
			for (int x = 0; x < input.length(); x++) {
				if (input.at(x) == 'A') {
					start = { i,x,k, 0, input.at(x) };
				}
				in.at(k).at(i).push_back({i,x,k, 0, input.at(x) });
			}
		}
	}

	Maze maze(in, start);
	cout << maze.BFSTraverse();
}