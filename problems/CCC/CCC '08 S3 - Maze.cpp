#include <iostream>
#include <vector>
#include <deque>
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
		r = grid[0].size();
		c = grid.size();
	}


	
	int traverse() {
		//BFS variables
		deque<pair<int, int>> next;
		deque < pair<int, int>> step;
		pair<int, int> current;
		int counter = 0;

		//initial pos
		step.push_back({ 0,0 });
		

		//use BFS to find shortest path
		while (true) {
			
			
			//END CASES
			if (step.empty()) {
				if (next.empty()) {
					//end case
					break;
				} {
					//next step
					counter++;
					step = next;
					next.clear();
				}
			}
			//check if end reached
			if (current.first == r - 1 && current.second == c - 1) {
				break;
			}

			current = { step.front().first,step.front().second };
			step.pop_front();
			
			
			//check valid position
			if (current.first < r && current.first >= 0 && current.second < c && current.second >= 0) {
				
				switch (grid[current.first][current.second]) {
				case '+':
					//all 4 directions
					step.push_back({ current.first + 1,current.second });
					step.push_back({ current.first,current.second + 1 });
					step.push_back({ current.first - 1,current.second });
					step.push_back({ current.first ,current.second - 1 });
					break;
				case '-':
					//only lr
					step.push_back({ current.first ,current.second + 1 });
					step.push_back({ current.first ,current.second - 1 });
				case '|':
					//only ud
					step.push_back({ current.first + 1,current.second });
					step.push_back({ current.first - 1,current.second });
				}
				//mark current tile
				grid[current.first][current.second] = '*';
			}
		}
		return counter;
	}

};

int main() {
	int r, c; vector<vector<char>> vec;
	cin >> r >> c;
	for (int k = 0; k < r; k++) {
		vec.push_back({});
		for (int i = 0; i < c; i++) {
			char in; cin >> in; vec[k].push_back(in);
		}
	}
	maze a(vec);
	cout << a.traverse();
}