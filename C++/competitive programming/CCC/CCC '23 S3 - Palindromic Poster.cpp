#include <iostream>
#include <vector>
using namespace std;

//CCC '23 S3 - Palindromic Poster
//https://dmoj.ca/problem/ccc23s3
//8-18-2025

//literally just a letter that makes the final solution look cooler
#define sillyLetter 'h'

//makes a palindrome of 0s and 1s
//returns an empty string if impossible
string makePalindrome(int length, int n) {
	//invalid length
	if (n > length) return "";

	string result = string(length, '0');
	if (n % 2 == 1) {
		if (length % 2 == 1) {
			//fill center
			result.at(length / 2) = '1';
		}
		else {
			return "";
		}
	}

	//fill ones from both sides
	for (int k = 0; k < n / 2; k++) {
		result.at(k) = '1';
		result.at(result.length() - 1 - k) = '1';
	}

	return result;
}

//makes a non palindome or 0s and 1s
//returns an empty string if impossible
string makeNonPalindrome(int length, int n) {
	//invalid length
	if (length <= 1) return "";

	string result = string(length, '0');
	//fill in ones from left only
	for (int k = 0; k < n; k++) {
		result.at(k) = '1';
	}
	return result;
}

//construct grid from axes
//1 denotes #-------, 0 denotes #-------#
vector<vector<int>> constructGrid(string rowAxis, string colAxis, int rows, int cols) {
	vector<vector<int>> grid = vector<vector<int>>(rows, vector<int>(cols));
	for (int r = 0; r < rows; r++) {
		grid[r][0] += rowAxis.at(r) - '0';
		if (rowAxis.at(r) == 0) grid[r][cols - 1] = grid[r][0];
	}
	for (int c = 0; c < cols; c++) {
		grid[0][c] += colAxis.at(c) - '0';
		if (colAxis.at(c) == 0) grid[rows - 1][c] = grid[0][c];
	}
	return grid;
}

int main() {
	int rows, cols; cin >> rows >> cols;
	int pRows, pCols; cin >> pRows >> pCols;

	string rowAxis, colAxis;
	bool valid = true;

	
	if (pRows == rows) {
		//all rows used, column axis needs to be palindrome
		colAxis = makePalindrome(cols, cols - pCols);
	}
	else {
		colAxis = makeNonPalindrome(cols, cols - pCols);
	}
	if (colAxis.empty()) valid = false;


	if (pCols == cols) {
		//all cols used, row axis needs to palindrome
		rowAxis = makePalindrome(rows, rows - pRows);
	}
	else {
		rowAxis = makeNonPalindrome(rows, rows - pRows);
	}
	if (rowAxis.empty()) valid = false;

	if (valid) {
		vector<vector<int>> grid = constructGrid(rowAxis, colAxis, rows, cols);

		for (auto r : grid) {
			for (int c : r) {
				cout << (char)(sillyLetter + c);
			}
			cout << endl;
		}
	}
	else {
		cout << "IMPOSSIBLE";
	}
	

}