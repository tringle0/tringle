#include <iostream>
#include <string>
#include <vector>
using namespace std;

//WORD SEARCH
//given a grid of letters, find how many times a word can be created by connecting adjacent letters
//letters can turn in any direction and words do not neccesarily have to be a straight line
//input: target, rows, columns, grid contents

bool followword(int row, int col, vector<vector<char>>& grid, string &target, int check) {
	cout << row << " " << col << endl;
	if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return false;
	if (grid[row][col] == target.at(check)) {
		if (check == target.length() - 1) {
			//checked all - matching
			cout << "found\n" << endl;
			return true;
		}
		else {
			bool foundword = false;
			//check around 8 directions
			for (int k = 0; k < 3; k++) {
				for (int i = 0; i < 3; i++) {
					if (!(k == 1 && i == 1)) {
						foundword = foundword || followword(row + k - 1, col + i - 1, grid, target, check + 1);
					}
				}
			}
			return foundword;
		}
	}
	return false;
	
}

int main() {
	string target; cin >> target;
	int rows, columns; cin >> rows >> columns;
	vector<vector<char>> grid;
	for (int k = 0; k < rows; k++) {
		grid.push_back({});
		for (int i = 0; i < columns; i++) {
			char in; cin >> in;
			grid[k].push_back(in);
		}
	}
	int counter = 0;
	for (int k = 0; k < rows; k++) {
		for (int i = 0; i < columns; i++) {
			if (grid[k][i] == target.at(0) && followword(k,i,grid,target,0)) {
				counter++;
			}
		}
	}
	cout << counter;
}