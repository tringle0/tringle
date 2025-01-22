#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//CCC '08 S3 - Maze
//https://dmoj.ca/problem/ccc08s3
//1-22-2025 wip

class maze {
public:
	int r, c; //size of grid
	vector<vector<char>> grid;
	maze(vector<vector<char>> grid) {
		this->grid = grid;
		r = grid.size();
		c = grid[0].size();
	}

	struct tile {
		//row, collumn, distance
		int r, c, d;
	};
	
	int traverse() {
		//BFS variables
		queue < tile> step;
		tile current;
		//initial pos
		step.push({ 0,0,1 });
		

		//use BFS to find shortest path
		while (true) {

			//not found
			if (step.empty()) return -1;

			current = { step.front().r,step.front().c,step.front().d};
			step.pop();
			
			//check if end reached
			if (current.r == r - 1 && current.c == c - 1) {
				break;
			}

			//check valid position
			if (current.r < r && current.r >= 0 && current.c < c && current.c >= 0) {
				switch (grid[current.r][current.c]) {

				case '+':
					//all 4 directions
					step.push({ current.r + 1,current.c,current.d+1 });
					step.push({ current.r,current.c + 1,current.d + 1 });
					step.push({ current.r - 1,current.c ,current.d + 1 });
					step.push({ current.r ,current.c - 1,current.d + 1 });
					break;
				case '-':
					//only lr
					step.push({ current.r ,current.c + 1,current.d + 1 });
					step.push({ current.r ,current.c - 1,current.d + 1 });
					break;
				case '|':
					//only ud
					step.push({ current.r + 1,current.c,current.d + 1 });
					step.push({ current.r - 1,current.c,current.d + 1 });
					break;
				}
				//mark current tile
				grid[current.r][current.c] = '*';
			}
		}
		return current.d;
	}

};

int main() {
	int n; cin >> n;
	int r, c;;
	for (int k = 0; k < n; k++) {
		cin >> r >> c;
		vector<vector<char>> vec(r, vector<char>(c, 0));
		for (int k = 0; k < r; k++) {
			for (int i = 0; i < c; i++) {
				cin >> vec[k][i];
			}
		}
		if (vec[r - 1][c - 1] == '*') {
			cout << -1 << endl;
		}
		else {
			maze a(vec);
			cout << a.traverse() << endl;
		}
		
	}
}