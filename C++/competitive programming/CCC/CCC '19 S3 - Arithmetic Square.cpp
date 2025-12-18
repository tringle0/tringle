#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <string>
#include <random>
using namespace std;

//CCC '19 S3 - Arithmetic Square
//https://dmoj.ca/problem/ccc19s3
//12-15-2025
using namespace std;

#define X 2000000

class ArithmeticSquare {
public: 
	vector<int> grid;

	enum fillResult {
		filled, notFilled, invalid,
		finished //used only for fillPass()
	};

	//pair number to fill, assumption?
	int recentAssumption = 0;
	stack<int> fills;
	void fill(int pos, int n, bool assumption) {
		grid.at(pos) = n;
		//set the last assumption checkpoint
		if (assumption) {
			recentAssumption = pos;
			fills = stack<int>();
		}
		else {
			//add the position filled to the history
			fills.push(pos);
		}
	}

	void backTrack() {
		while (!fills.empty()) {
			grid.at(fills.top()) = X;
			fills.pop();
		}
		grid.at(recentAssumption)++;
	}

	fillResult canFillSquare(int r, int c) {
		//determine which axis to use
		pair<bool, bool> canFill = {true,true}; //whether the row,col has enough information
		for (int k = 0; k < 3; k++) {
			if (k != r && grid.at(3 * k + c) == X) canFill.first = false;
			if (k != c && grid.at(3 * r + k) == X) canFill.second = false;
		}
		int pos;				//the position in the row/col of the element to be filled 
		bool vertical = true;	//row or col (col priority)
		if (canFill.first) { pos = r; vertical = true; }
		else if (canFill.second) { pos = c; vertical = false; }
		else return notFilled;	//case where not enough information to fill the square

		int filledNum;		//result number to be filled
		vector<int> nums;	//representing the 3 numbers of the row/col
		if (vertical)	nums = { grid.at(c), grid.at(c + 3),grid.at(c + 6) };
		else			nums = { grid.at(r*3), grid.at(r*3 + 1), grid.at(r*3 + 2) };

		//check invalid case
		if (pos == 1 && (nums.at(0) + nums.at(2)) % 2 == 1) return invalid;

		//find the missing number
		switch (pos) {
			case 0: filledNum = 2 * nums.at(1) - nums.at(2);	break;
			case 1: filledNum = (nums.at(0) + nums.at(2))/2;	break;
			case 2: filledNum = 2 * nums.at(1) - nums.at(0);	break;
		}
		fill(3*r + c, filledNum, false);
		
		//re check if correct
		if (vertical)	nums = { grid.at(c), grid.at(c + 3),grid.at(c + 6) };
		else			nums = { grid.at(r * 3), grid.at(r * 3 + 1), grid.at(r * 3 + 2) };
		if (nums.at(0) + nums.at(2) != 2 * nums.at(1)) return invalid;

		return filled;
	}

	//iterates top-left to bottom-right to find any squares to fill
	fillResult fillPass() {
		bool found = false;
		bool foundUnfilled = false;
		for (int r = 0; r < 3; r++) {
			for (int c = 0; c < 3; c++) {
				if (grid.at(r * 3 + c) != X) continue;
				fillResult squareResult = canFillSquare(r, c);

				//fill case
				if (squareResult == filled) found = true;
				//invalid case: backtrack
				else if (squareResult == invalid) return invalid;
				else if (squareResult == notFilled) foundUnfilled = true;
			}
		}
		if (!foundUnfilled) return finished;
		return found ? filled : notFilled;
	}

	void fillGrid() {
		
		while (true) {
			fillResult passResult = fillPass();


			if (passResult == finished) break;

			int assumePos = 0;
			while (grid.at(assumePos) != X) assumePos++;

			if (passResult == notFilled) {
				fill(assumePos, -1000, true);
			}
			if (passResult == invalid) {
				backTrack();
			}
			
		}
	}

	void printGrid() {
		for (int r = 0; r < 3; r++) {
			for (int c = 0; c < 3; c++) {
				if (grid.at(r * 3 + c) == X) cout << "X ";
				else cout << grid.at(r * 3 + c) << ' ';
			}
			cout << endl;
		}
	}
};

int main() {
	ArithmeticSquare sq;

	for (int k = 0; k < 9; k++) {
		string in; cin >> in;
		if (in == "X") sq.grid.push_back(X);
		else sq.grid.push_back(stoi(in));
	}

	sq.fillGrid();
	sq.printGrid();
}