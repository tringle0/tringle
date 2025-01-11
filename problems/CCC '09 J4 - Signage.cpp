#include <iostream>
#include <string>
#include <vector>
using namespace std;

//CCC '09 J4 - Signage
//1-11-2025

void print(vector<string> currentline, int l, int linelength) {
	//print
	
	int totalspaces = l - linelength;
	int minspaces = (currentline.size() == 1 ? 1 : totalspaces / (currentline.size() - 1));
	int extraspaces = totalspaces - minspaces * (currentline.size() - 1);
	for (int i = 0; i < currentline.size() - 1; i++) {
		cout << currentline.at(i);
		for (int k = 0; k < minspaces; k++) {
			cout << ".";
		}
		if (extraspaces > 0) {
			cout << ".";
			extraspaces--;
		}
	}
	cout << currentline.at(currentline.size() - 1);
	if (currentline.size() == 1) {
		for (int k = 0; k < l-linelength; k++) {
			cout << ".";
		}
	}
	
	cout << endl;
}

int main() {
	int l; cin >> l;
	vector<string> msg = { "WELCOME","TO","CCC","GOOD","LUCK","TODAY" };
	int linelength = 0;
	int minspace = 0;
	vector<string> currentline;
	for (int k = 0; k < msg.size(); k++) {
		if (linelength + minspace + msg.at(k).length() <= l) {
			currentline.push_back(msg.at(k));
			linelength += msg.at(k).length();
			minspace++;
		}
		else {
			minspace = 0;
			print(currentline, l, linelength);
			linelength = 0;
			currentline.clear();
			k--;
		}
	}
	if (!currentline.empty()) {
		print(currentline, l, linelength);
	}
	
}