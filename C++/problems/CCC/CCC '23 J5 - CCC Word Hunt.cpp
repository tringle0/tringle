#include <vector>
#include <string>
#include <iostream>
using namespace std;

//CCC '23 J5 - CCC Word Hunt
//https://dmoj.ca/problem/ccc23j5
//1-14-2025

int wordhunt(vector<vector<char>>& grid, int r, int c, int dr, int dc, string target, int read, bool canturn) {
	int total = 0;
	if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) return 0;
	if (dr == 0 && dc == 0) {
		//set init direction
		int sum = 0;
		for (int k = 0; k < 3; k++) {
			for (int i = 0; i < 3; i++) {
				if (!(k == 1 && i == 1)) {
					if (r + k - 1>= 0 && r + k - 1 < grid.size() && c + i - 1>= 0 && c + i - 1 < grid[0].size()) {
						sum += wordhunt(grid, r + k - 1, c + i - 1, k - 1, i - 1, target, 1, canturn);
					}
				}
			}
		}
		return sum;
	}
	if (grid[r][c] == target.at(read)) {
		//cout << target.at(read) << " " << r << "," << c << endl;
		if (read >= target.length() - 1) {
			return 1;
		}
		//check for possible turns
		int turns = 0;
		if (canturn) {
			//check perpendiculars
			if (r -dc >= 0 && r - dc < grid.size() && c + dr >= 0 && c + dr < grid[0].size()) {
				turns += wordhunt(grid, r - dc, c + dr, -dc, dr, target, read + 1, false);
			}
			if (r + dc >= 0 && r + dc < grid.size() && c - dr >= 0 && c - dr < grid[0].size()) {
				turns += wordhunt(grid, r + dc, c - dr, dc, -dr, target, read + 1, false);
			}
		}
		return turns + wordhunt(grid, r + dr, c + dc, dr, dc, target, read+1, canturn);
	}
	return 0;

}

int main() {
	string target; cin >> target;
	int r, c; cin >> r >> c;
	vector<vector<char>> grid;
	for (int k = 0; k < r; k++) {
		grid.push_back({});
		for (int i = 0; i < c; i++) {
			char in; cin >> in; grid[k].push_back(in);
		}
	}
	int ans = 0;
	for (int k = 0; k < r; k++) {
		for (int i = 0; i < c; i++) {
			if (grid[k][i] == target.at(0)) {
				ans+=wordhunt(grid, k, i, 0, 0, target, 0, true);
			}
		}
	}
	cout << ans;
}