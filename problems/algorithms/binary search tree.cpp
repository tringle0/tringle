#include <iostream>
using namespace std;

// binary search tree
// 1/9/2025 - wip

//single node
struct Node {
public:
	int value;
	struct Node* left = NULL, * right = NULL;
	Node() {
		value = -1;
	}
	Node(int val) {
		value = val;
		left = NULL; right = NULL;
	}
};

//binary search tree
class bst {

public:
	Node* root = nullptr;

	void insert(int value) {
		cout << value << ": ";
		root = inserter(root, value);
		cout << endl;
	}

private:
	Node* inserter(Node* n, int v) {
		
		if (n == nullptr) {
			n = new Node(v);
			cout << "root ";
		}
		else {
			if (v < n->value) {
				n ->left = inserter(n->left, v);
				cout << "left ";
			}
			else {
				n->right = inserter(n->right, v);
				cout << "right ";
			}
		}
		
		return n;
	}
};

int main() {
	bst tree;
	tree.insert(6);
	tree.insert(3);
	tree.insert(7);
	tree.insert(2);
}