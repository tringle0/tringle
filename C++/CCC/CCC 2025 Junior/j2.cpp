#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
	int d; cin >> d;
	int e; cin >> e;
	int donuts = d;
	for (int k = 0; k < e; k++) {
		char action; cin >> action;
		int amount; cin >> amount;
		if (action == '+') {
			donuts += amount;
		}
		if (action == '-') {
			donuts -= amount;
		}
	}
	cout << donuts;
}