#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <unordered_set>

using namespace std;

//DUPE QUEUE
//add letters from a word into a sorted string (always sorted)
//check how many different letters have passed through index i
//input: index i, word

string swap(string& word, int a, int b) {
	int temp = 0;
	temp = word.at(a);
	word.at(a) = word.at(b);
	word.at(b) = temp;
	return word;
}

string quicksort(string& word, int lower, int upper) {
	if (upper <= lower) return word;
	int pivot = word.at(upper);
	int i = lower;
	for (int k = lower; k < upper; k++) {
		if (word.at(k) < word.at(upper)) {
			word = swap(word, k, i);
			i++;
		}
	}

	word = swap(word, i, upper);
	
	int split = i;
	word = quicksort(word, lower, split - 1);
	word = quicksort(word, split + 1, upper);
	return word;
}

int dupequeue(string word, int checkpos) {
	string newword = "";
	unordered_set<char> uniques;
	int counter = 0;
	for (int k = 0; k < word.length(); k++) {
		char current = (char)toupper(word.at(k));
		if (isalpha(current)) {
			newword += current;
			quicksort(newword,0,newword.length()-1);
			if (newword.length() > checkpos) {
				if (uniques.count(newword.at(checkpos)) == 0) {
					uniques.insert(newword.at(checkpos));
					counter++;
				}
					
			}
		}
	}
	return counter;
}

int main() {
	int checkpos; string word; 
	cin >> checkpos; checkpos--;
	getline(cin, word);
	cout << dupequeue(word, checkpos);
	
}