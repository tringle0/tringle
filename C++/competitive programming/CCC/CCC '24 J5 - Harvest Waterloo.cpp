#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//CCC '24 J5 - Harvest Waterloo
//https://dmoj.ca/problem/ccc24j5
//1-13-2025

class field {
public:
	vector<vector<char>> grid;
	int points = 0;
	int w, h;
	field(vector<vector<char>> in) {
		grid = in; w = grid[0].size(); h = grid.size();
	}
	unordered_map<char, int> ptvalues = {
		{'S',1},{'M',5},{'L',10},{'_',0}
	};

	int walk(int x, int y) {
		if (x < 0 || x >= w || y < 0 || y >= h) {
			return 0;
		}
		else {
			if (grid[y][x] == '*') {
				return 0;
			}
			int current = ptvalues[grid[y][x]];
			grid[y][x] = '*';
			return current + walk(x, y - 1) + walk(x + 1, y) + walk(x - 1, y) + walk(x, y + 1);
		}

	}

};

int main() {
	vector<vector<char>> input;
	int w, h; cin >> h >> w;
	for (int k = 0; k < h; k++) {
		input.push_back({});
		for (int i = 0; i < w; i++) {
			char in; cin >> in;
			input[k].push_back(in);
		}
	}
	int x, y; cin >> y >> x;
	cout << field(input).walk(x, y);

}