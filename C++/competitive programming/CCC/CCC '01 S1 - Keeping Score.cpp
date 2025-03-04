#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//CCC '01 S1 - Keeping Score
//https://dmoj.ca/problem/ccc01s1
//2-26-2025
unordered_map<char, int> cardvalues = { {'A',4}, {'K',3}, {'Q',2}, {'J',1} };
string input; int k = 1; int total = 0;
void printline(string suit, char endtarget) {
	int counter = 0, value = 0;
	cout << suit << " ";
	while (input.at(k) != endtarget) {
		cout << input.at(k) << " ";
		value += cardvalues[input.at(k)];
		counter++;
		k++;
	}
	if (counter <= 2) {
		value += 3 - counter;
	}
	cout << value << endl;
	total += value;
	k++;
}

int main() {
	cin >> input; input += '/';
	cout << "Cards Dealt              Points\n";
	printline("Clubs", 'D');
	printline("Diamonds", 'H');
	printline("Hearts", 'S');
	printline("Spades", '/');
	cout << "     Total " << total << endl;
}	