#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

//CCC '21 S1 - Crazy Fencing
//https://dmoj.ca/problem/ccc21s1
//3-24-2025

int main() {
	int n; cin >> n;
	vector<double> heights;
	vector<double> widths;
	for (int k = 0; k < n + 1; k++) {
		int input; cin >> input;
		heights.push_back(input);
	}
	for (int k = 0; k < n; k++) {
		int input; cin >> input;
		widths.push_back(input);
	}
	long double totalArea = 0;
	for (int k = 0; k < widths.size(); k++) {
		//triangle area
		double triangleHeight = abs(heights.at(k) - heights.at(k + 1));
		totalArea += (triangleHeight * widths.at(k))/2;

		//square area
		double squareHeight = min(heights.at(k), heights.at(k + 1));
		totalArea += widths.at(k) * squareHeight;
	}

	cout << fixed << totalArea;
}