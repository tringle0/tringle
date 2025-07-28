#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//CCC '14 S2 - Assigning Partners
//https://dmoj.ca/problem/ccc14s2
//6-18-2025

int main() {
	int n; cin >> n;
	vector<string> names1;
	vector<string> names2;
	bool good = true;
	for (int k = 0; k < n; k++) {
		string in; cin >> in;
		names1.push_back(in);
	}
	unordered_map<string, string> pairs;
	for (string s : names1) {
		string in; cin >> in;
		names2.push_back(in);
		if(pairs[in].empty())
		pairs[in] = s;	
		pairs[s] = in;
	}
	
	for (int k = 0; k < n; k++) {
		if (names2.at(k) != pairs[names1.at(k)]) good = false;
		if (names1.at(k) != pairs[names2.at(k)]) good = false;
		if (names2.at(k) == pairs[names2.at(k)]) good = false;
		if (names1.at(k) == pairs[names1.at(k)]) good = false;
	}
	cout << (good?"good":"bad");
}