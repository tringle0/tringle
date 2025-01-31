#include <iostream>
#include <math.h>
using namespace std;

//An Animal Contest 1 P1 - Alpaca Shapes
//https://dmoj.ca/problem/aac1p1
//1-18-2025

int main() {
	int s, c; cin >> s >> c;
	int square = s * s;
	int circ = 3.14 * c * c;
	cout << (square > circ ? "SQUARE" : "CIRCLE");
}