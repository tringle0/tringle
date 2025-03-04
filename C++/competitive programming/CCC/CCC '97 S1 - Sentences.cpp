#include <iostream>
#include <vector>
#include <string>
using namespace std;

//CCC '97 S1 - Sentences
//https://dmoj.ca/problem/ccc97s1
//2-24-2025

int main() {
	string input; getline(cin, input); int n = stoi(input);
	for (int k = 0; k < n; k++) {
		vector<string> subject, verb, object; 
		getline(cin, input); int s = stoi(input);
		getline(cin, input); int v = stoi(input);
		getline(cin, input); int o = stoi(input);
		
		for (int k = 0; k < s; k++) {
			getline(cin, input);
			subject.push_back(input);
		}
		for (int k = 0; k < v; k++) {
			getline(cin, input);
			verb.push_back(input);
		}
		for (int k = 0; k < o; k++) {
			getline(cin, input);
			object.push_back(input);
		}
		for (int k = 0; k < subject.size(); k++) {
			for (int j = 0; j < verb.size(); j++) {
				for (int p = 0; p < object.size(); p++) {
					cout << subject.at(k) << " " << verb.at(j) << " " << object.at(p) << ".\n";
				}
			}
		}
	}
}