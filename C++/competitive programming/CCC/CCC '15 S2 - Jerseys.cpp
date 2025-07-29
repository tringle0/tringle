#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//CCC '15 S2 - Jerseys
//https://dmoj.ca/problem/ccc15s2
//7-29-2025

int main() {
	int j; cin >> j;
	int a; cin >> a;

	vector<char> jerseys;
	for (int k = 0; k < j; k++) {
		char in; cin >> in;
		jerseys.push_back(in);
	}
	unordered_set<int> taken;
	int counter = 0;
	for (int k = 0; k < a; k++) {
		char size; int number; cin >> size >> number;
		if (jerseys.at(number-1) <= size && taken.count(number) == 0 ) {
			counter++;
			taken.insert(number);
		}
	}
	cout << counter;
}