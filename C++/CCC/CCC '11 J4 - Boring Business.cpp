#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

//CCC '11 J4 - Boring Business
//https://dmoj.ca/problem/ccc11j4
//1-12-2025

string pos(int posx, int posy) {
	return to_string(posx) + " " + to_string(posy);
}

int main() {
	unordered_set<string> tunnel = {
		"0 -1","0 -2","0 -3","1 -3", "2 -3", "3 -3", "3 -4",
		"3 -5", "4 -5", "5 -5", "5 -4", "5 -3", "6 -3", "7 -3",
		"7 -4", "7 -5", "7 -6", "7 -7", "6, -7", "5 -7", "4 -7",
		"3 -7", "2 -7", "1 -7", "0 -7", "-1 -7", "-1 -6", "-1 -5"
	};
	int posx = -1, posy = -5;
	int endposx; int endposy;
	while (true) {
		char input; int distance;
		cin >> input >> distance;
		if (input == 'q') break;
		bool danger = false;
		for (int k = 0; k < distance; k++) {
			tunnel.insert(pos(posx, posy));
			switch (input) {
			case 'u':
				posy++;
				break;
			case 'r':
				posx++;
				break;
			case 'd':
				posy--;
				break;
			case 'l':
				posx--;
				break;
			}
			
			if (tunnel.count(pos(posx, posy)) > 0) {
				danger = true;
			}
		}
		if (danger) {
			cout << posx << " " << posy << " DANGER";
			return 0;
		}
		else {
			cout << posx << " " << posy << " safe\n";
		}
	}
}