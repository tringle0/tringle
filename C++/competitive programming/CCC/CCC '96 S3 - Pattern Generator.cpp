#include<iostream>
using namespace std;

//CCC '96 S3 - Pattern Generator
//https://dmoj.ca/problem/ccc96s3
//8-11-2025



void findPatternsRec(string current, int &targetLength, int ones, int &targetOnes) {
	//end case
	if (ones > targetOnes) return;
	if (current.length() == targetLength) {
		if(ones == targetOnes)
		cout << current << endl;
		return;
	}

	findPatternsRec(current + '1', targetLength, ones + 1, targetOnes);
	findPatternsRec(current + '0', targetLength, ones, targetOnes);
	return;
}

void findPatterns(int length, int ones) {
	cout << "The bit patterns are\n";
	findPatternsRec("", length, 0, ones);
}

int main() {
	int n; cin >> n;
	for (int k = 0; k < n; k++) {
		int length; cin >> length;
		int ones; cin >> ones;
		
		findPatterns(length, ones);
		if (k < n - 1) cout << endl;
	}
}