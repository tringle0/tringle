#include <iostream>
#include <vector>
using namespace std;

//CCC '01 S2 - Spirals (Exact Version)
//https://dmoj.ca/problem/ccc01s2
//7-28-2025

typedef vector<vector<int>> matrix;




class spiral {
private: 
	matrix grid;
	bool completed;
	int start, end;

	bool checkCompleted(int n) {
		return completed = n >= end;
	}

	matrix expandUL(matrix grid) {
		//get first value
		int start = grid.front().back();
		if (checkCompleted(start)) return grid;
		//new row at top
		grid.insert(grid.begin(), vector<int>(grid.size()));
		for (int k = grid.front().size() - 1; k >= 0; k--) {
			if (checkCompleted(start)) break;
			grid.front()[k] = ++start;
			
		}
		if (checkCompleted(start)) return grid;
		//new col at left
		for (int k = 0; k < grid.size(); k++) {
			if (checkCompleted(start)) 
				grid[k].insert(grid[k].begin(), 0);
			else
				grid[k].insert(grid[k].begin(), ++start);
			
		}
		return grid;
	}

	matrix expandDR(matrix grid) {
		//get first value
		int start = grid.back().front();
		if (checkCompleted(start)) return grid;
		//new row at bottom
		grid.push_back(vector<int>(grid.size()));
		for (int k = 0; k < grid.back().size(); k++) {
			if (checkCompleted(start)) break;
			grid.back()[k] = ++start;
		}
		if (checkCompleted(start)) return grid;
		//new col at right
		for (int k = grid.size() - 1; k >= 0; k--) {
			if (checkCompleted(start))
				grid[k].push_back(0);
			else
			grid[k].push_back(++start);
			
		}
		return grid;
	}

public:
	spiral(int start, int end) {
		grid.push_back(vector<int>(1));
		grid[0][0] = start;
		this->start = start;
		this->end = end;
		completed = false;
	}

	void createSpiral() {
		while (true) {
			grid = expandDR(grid);
			if (completed) break;
			grid = expandUL(grid);
			if (completed) break;
		}
	}

	void print() {
		vector<int> columnPadding(grid[0].size(), -1);
		for (int k = 0; k < grid.size(); k++) {
			for (int i = 0; i < grid[k].size(); i++) {

				if (columnPadding[i] == -1) {
					columnPadding[i] = 0;
					for (int j = 0; j < grid.size(); j++) {
						if (grid[j][i] > 9) {
							columnPadding[i] = 1;
							break;
						}
					}
				}
				


				if(grid[k][i] <= 9 && columnPadding[i]==1) cout << ' ';
				if (grid[k][i] == 0) 
					cout << " ";
				else
				cout << grid[k][i];
				if (i < grid[k].size() - 1) cout << ' ';
			}
			if(k < grid.size()-1) cout << '\n';
		}


	}

	
	
};


int main() {
	int n; cin >> n;
	for (int k = 0; k < n; k++) {
		int start, end; cin >> start >> end;
		spiral s(start, end);
		s.createSpiral();
		s.print();
		if (k < n - 1) cout << "\n\n";
	}
	cout << endl;
	
}