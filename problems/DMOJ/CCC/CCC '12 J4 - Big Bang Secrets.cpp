#include <iostream>
#include <string>
using namespace std;

//CCC '12 J4 - Big Bang Secrets
//https://dmoj.ca/problem/ccc12j4
//1/14/2025


int main() {
	int key; cin >> key;
	string word; cin >> word;
	for (int k = 0; k < word.length(); k++) {
		word.at(k) = (word.length() * 3 * 26 + (word.at(k) - 'A') - 3 * (k + 1) - key) % 26 + 'A';
	}
	cout << word;
}