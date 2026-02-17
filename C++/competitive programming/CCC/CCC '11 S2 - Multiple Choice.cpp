#include <iostream>
#include <vector>
using namespace std;

//CCC '11 S2 - Multiple Choice
//https://dmoj.ca/problem/ccc11s2
//2-17-2026

int main() {
	int N; cin >> N;
	char input;
	vector<char> a, b;
	int counter = 0;
	for (int k = 0; k < N; k++) { cin >> input; a.push_back(input); }
	for (int k = 0; k < N; k++) { cin >> input; b.push_back(input); }
	for (int k = 0; k < N; k++) { if (a.at(k) == b.at(k)) counter++; }
	cout << counter;
}