#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//CCC '22 S2 - Good Groups
//https://dmoj.ca/problem/ccc22s2
//7-29-2025

int main() {
	vector<pair<string, string>> goodPairs;
	vector<pair<string, string>> badPairs;

	unordered_map<string, int> groupOfPerson;

	int x; cin >> x;
	for (int k = 0; k < x; k++) {
		string p1, p2; cin >> p1 >> p2;
		goodPairs.push_back({ p1,p2 });
	}
	int y; cin >> y;
	for (int k = 0; k < y; k++) {
		string p1, p2; cin >> p1 >> p2;
		badPairs.push_back({ p1,p2 });
	}

	int g; cin >> g;
	for (int k = 0; k < g; k++) {
		for (int i = 0; i < 3; i++) {
			string person; cin >> person;
			groupOfPerson[person] = k;
		}
	}

	int violations = 0;
	for (auto k : goodPairs) {
		if (groupOfPerson[k.first] != groupOfPerson[k.second]) violations++;
	}
	for (auto k : badPairs) {
		if (groupOfPerson[k.first] == groupOfPerson[k.second]) violations++;
	}

	cout << violations;
}