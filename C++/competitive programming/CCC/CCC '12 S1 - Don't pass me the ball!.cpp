#include <iostream>
using namespace std;

//CCC '12 S1 - Don't pass me the ball!
//https://dmoj.ca/problem/ccc12s1
//7-29-2025

int main() {
	int in; cin >> in;
	cout <<  --in *  (in - 1) * (in - 2) / 6;
}