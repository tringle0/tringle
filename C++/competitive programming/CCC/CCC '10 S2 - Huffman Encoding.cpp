#include <iostream>
#include <vector>
using namespace std;

//CCC '10 S2 - Huffman Encoding
//https://dmoj.ca/problem/ccc10s2
//6-17-2025

struct node {
	char letter;
	int left = -1, right = -1;
	node(char c) {
		letter = c;
	}
	bool isLeaf() {
		return left == -1 && right == -1;
	}
};

class bst {
public:
	vector<node> nodes;
	bst() {
		nodes.push_back(node(' '));
	}
	void addNode(string seq, char letter) {
		int pos = 0;
		for (int k = 0; k < seq.length(); k++) {
			//left
			if (seq.at(k) == '0') {
				if (nodes.at(pos).left == -1) {
					
					nodes.at(pos).left = nodes.size();
					pos = nodes.size();
					nodes.push_back(node(' '));
				}
				else {
					pos = nodes.at(pos).left;
				}
			}
			//right
			else {
				if (nodes.at(pos).right == -1) {
					
					nodes.at(pos).right = nodes.size();
					pos = nodes.size();
					nodes.push_back(node(' '));
				}
				else {
					pos = nodes.at(pos).right;
				}
			}
		}
		nodes.back().letter = letter;
	}

	string decodeMessage(string message) {
		message += "/";
		string decodedMessage = "";
		int pos = 0;
		for (int k = 0; k < message.length(); k++) {
			if (nodes.at(pos).isLeaf()) {
				decodedMessage += nodes.at(pos).letter;
				pos = 0;
				k--;
			}
			else {
				if (message.at(k) == '0') {
					pos = nodes.at(pos).left;
				}
				else {
					pos = nodes.at(pos).right;
				}
			}
		}
		return decodedMessage;
	}
};

int main() {
	bst tree;
	int n; cin >> n;
	for (int k = 0; k < n; k++) {
		char letter; string path;
		cin >> letter >> path;
		tree.addNode(path, letter);
	}
	string input; cin >> input;
	cout << tree.decodeMessage(input);
}