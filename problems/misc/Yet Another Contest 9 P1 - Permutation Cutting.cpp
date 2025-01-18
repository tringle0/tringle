#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//Yet Another Contest 9 P1 - Permutation Cutting
//https://dmoj.ca/problem/yac9p1
//1-11-2025

void printvec(vector<int> vec) {
	for (int k = 0; k < vec.size(); k++) {
		cout << vec.at(k) << " ";
	}
	cout << endl;
}

struct subvec {
	int pos1, pos2;
	int len;
};

int main() {
	int n; cin >> n;
	vector<int> nums; int input;
	bool equal = true;
	for (int k = 0; k < n; k++) {
		cin >> input; nums.push_back(input);
	}
	vector<int> target;
	for (int k = 0; k < n; k++) {
		cin >> input; target.push_back(input);
		if (target.at(k) != nums.at(k)) {
			equal = false;
		}
	}


	int longest = 0;
	int counter = 0;
	int read;
	subvec er;
	int delpos1 = 0, delpos2 = 0;
	while (!nums.empty()) {
		//find longest subsequence
		longest = 0;
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				read = 0;
				while (true) {
					if (!(k + read < n && i + read < n)) break;
					if (!(nums.at(k + read) == target.at(i + read) && !(nums.at(k + read) == 0 || target.at(i + read) == 0))) break;
					read++;

				}
				if (read > longest) {
					longest = read;
					er = { k, i, longest };
				}

			}
		}
		if (longest == 0) {
			break;
		}
		//remove (set all to 0)
		for (int i = 0; i < er.len; i++) {
			nums.at(er.pos1 + i) = 0;
			target.at(er.pos2 + i) = 0;
		}
		counter++;
	}
	cout << counter;

}