#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

//CCC '09 S2 - Lights Going On and Off
//https://dmoj.ca/problem/ccc09s2
//6-17-2025


string vecToString(vector<int> vec) {
	string out = "";
	for (int k : vec) {
		out += k + '0';
	}
	return out;
}


class lightBoard {
	vector<vector<int>> grid;
public:
	lightBoard(vector<vector<int>> g) {
		grid = g;
	}
	vector<vector<int>> flipRow(int row, vector<vector<int>> g) {
		for (int k = 0; k < g.at(row).size(); k++) {
			g.at(row).at(k) ^= g.at(row - 1).at(k);
		}
		return g;
	}
	//void print(vector<vector<int>> g) {
	//	for (auto i : g) {
	//		for (auto k : i) {
	//			cout << k << " ";
	//		}
	//		cout << endl;
	//	}
	//}

	int calculate() {
		return flipRowsRec(grid, 1);
	}

	unordered_set<string> found;
	unordered_map < string, vector<int>> dp;
	int flipRowsRec(vector<vector<int>> g, int row) {
		if (row >= g.size()) {
			
			string result = vecToString(g.back());
			if (found.count(result) == 0) {
				found.insert(result);
				return 1;
			}
			else {
				return 0;
			}
		}
		vector<vector<int>> flipped;
		if (dp.count(vecToString(g.at(row)) + vecToString(g.at(row-1))) == 0) {
			flipped = flipRow(row, g);
			dp[vecToString(g.at(row)) + vecToString(g.at(row - 1))] = flipped.at(row);
		}
		else {
			flipped = g;
			flipped.at(row) = dp[vecToString(g.at(row)) + vecToString(g.at(row - 1))];
		}
		
		if (flipped == g) {
			return flipRowsRec(g, row + 1);
		}
		else {
			return flipRowsRec(g, row + 1) + flipRowsRec(flipped, row + 1);
		}
		

	}

};

int main() {
	int rows, cols; cin >> rows >> cols;
	vector<vector<int>> grid;
	for (int k = 0; k < rows; k++) {
		grid.push_back({});
		for (int i = 0; i < cols; i++) {
			int in; cin >> in;
			grid.at(k).push_back(in);
		}
	}
	lightBoard board(grid);
	cout << board.calculate();
}