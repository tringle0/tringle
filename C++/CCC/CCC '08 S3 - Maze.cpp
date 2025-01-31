#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//CCC '08 S3 - Maze
//https://dmoj.ca/problem/ccc08s3
//1-22-2025 

class Maze {
public:
	//VARIABLES
	//dimensions of grid
	int r, c;
	//vector for storing grid values
	vector<vector<char>> grid;



	//constructor
	Maze(vector<vector<char>> grid) {
		this->grid = grid;
		r = grid.size();
		c = grid[0].size();
	}

	int bfsTraverse() {
		//properties for a single tile (row, column, distance from start)
		struct tile { int r, c, d; };
		//queue used for BFS
		queue <tile> bfs;
		//current position to check
		tile current = { 0,0,1 };


		//set initial position
		bfs.push(current);

		//use BFS to find shortest path
		while (true) {

			//return -1 when no path is found
			if (bfs.empty()) return -1;

			//set the current tile to be checked
			current = { bfs.front().r,bfs.front().c,bfs.front().d };
			bfs.pop();
			//check if end reached
			if (current.r == r - 1 && current.c == c - 1) {
				break;
			}

			//check if the tile is in range of the grid
			if (current.r < r && current.r >= 0 && current.c < c && current.c >= 0) {

				//add neighbors of the current tile based on its type
				switch (grid[current.r][current.c]) {
				case '+':
					//all 4 directions
					bfs.push({ current.r + 1,current.c,current.d + 1 });
					bfs.push({ current.r,current.c + 1,current.d + 1 });
					bfs.push({ current.r - 1,current.c ,current.d + 1 });
					bfs.push({ current.r ,current.c - 1,current.d + 1 });
					break;
				case '-':
					//only left-right
					bfs.push({ current.r ,current.c + 1,current.d + 1 });
					bfs.push({ current.r ,current.c - 1,current.d + 1 });
					break;
				case '|':
					//only up-down
					bfs.push({ current.r + 1,current.c,current.d + 1 });
					bfs.push({ current.r - 1,current.c,current.d + 1 });
					break;
				}

				//mark current tile as traversed
				grid[current.r][current.c] = '*';
			}
		}

		return current.d;
	}

	int Astar() {

		//properties for a single tile (row, column, distance from start, heuristic)
		struct tile { int r, c, d, h; };

		//comparator for pqueue
		struct heuristic {
			bool operator()(tile const& a, tile const& b) const {
				return a.h + a.d > b.h + b.d;
			}
		};
		//priority queue for A*
		priority_queue <tile, vector<tile>, heuristic > pq;
		//current position to check
		tile current = { 0,0,1, r + c };

		pq.push(current);
		while (true) {
			//check if queue is empty
			if (pq.empty()) return -1;

			//set current tile to be checked
			current = { pq.top().r,pq.top().c,pq.top().d, pq.top().h };

			//check if final position reached
			if (current.r == r - 1 && current.c == c - 1) return current.d;

			pq.pop();

			//check if the tile is in range of the grid
			if (current.r < r && current.r >= 0 && current.c < c && current.c >= 0) {
				//skip if grid is already marked
				if (grid[current.r][current.c] != '*') {

					//add neighbors of the current tile based on its type
					switch (grid[current.r][current.c]) {
					case '+':
						//all 4 directions
						pq.push({ current.r + 1,current.c,current.d + 1, abs(r - (current.r + 1)) + abs(c - current.c) });
						pq.push({ current.r,current.c + 1,current.d + 1, abs(r - current.r) + abs(c - (current.c + 1)) });
						pq.push({ current.r - 1,current.c ,current.d + 1, abs(r - (current.r - 1)) + abs(c - current.c) });
						pq.push({ current.r ,current.c - 1,current.d + 1, abs(r - current.r) + abs(c - (current.c - 1)) });
						break;
					case '-':
						// only left-right
						pq.push({ current.r ,current.c + 1,current.d + 1, abs(r - current.r) + abs(c - (current.c + 1)) });
						pq.push({ current.r ,current.c - 1,current.d + 1, abs(r - current.r) + abs(c - (current.c - 1)) });
						break;
					case '|':
						// only up-down
						pq.push({ current.r + 1,current.c,current.d + 1, abs(r - (current.r + 1)) + abs(c - current.c) });
						pq.push({ current.r - 1,current.c,current.d + 1, abs(r - (current.r - 1)) + abs(c - current.c) });
						break;
					}
				}

				//mark current tile as traversed
				grid[current.r][current.c] = '*';
			}

		}
		return current.d;
	}
};

int main() {
	//get input
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
			Maze a(vec);
			cout << a.bfsTraverse() << endl;
		}
	}
}