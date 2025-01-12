#include <iostream>
#include <string>
#include <math.h>
using namespace std;

//CCC '16 J3 - Hidden Palindrome
//1-11-2024

int main() {
	string word; cin >> word;
	int longest = 1 + (word.at(0) == word.at(1)?1:0);
	for (int k = 1; k < word.length() - 1; k++) {
		int left = k-1, right = k;
		//right matches center: shift right
		while (word.at(right) == word.at(k)) {
			right++;
			if (right >= word.length()) {
				right--;
				break;
			}
		}
		//palindrome found: shift both
		while(word.at(left) == word.at(right)) {
			left--; right++;
			if (left < 0 || right >= word.length()) {
				break;
			}
		}
		left++; right--;
		

		longest = max(longest, right - left+1);
	}
	cout << longest;
} 