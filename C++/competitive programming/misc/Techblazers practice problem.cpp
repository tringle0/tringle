#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

struct Component {
	char type, color, size;
};

class PartSet {
public:
	vector<Component> components;

	void addPart(Component hand) {
		int matched = 0;
		if (hand.color == components.back().color) matched++;
		if (hand.type == components.back().type) matched++;
		if (hand.size == components.back().size) matched++;
		if (matched >= 2) {
			components.push_back(hand);
		}
	}

	void printParts() {
		for (int k = 0; k < components.size(); k++) {
			cout << components.at(k).type << "-" << components.at(k).color << "-" << components.at(k).size << ' ';
		}
	}
	
};

int main() {
	PartSet robot1;
	PartSet robot2;
	PartSet hand;

	string in;
	cin >> in;
	robot1.components = { {in.at(0),in.at(2),in.at(4)} };
	cin >> in;
	robot2.components = { {in.at(0),in.at(2),in.at(4)} };

	while (true) {
		cin >> in;
		if (in == "end") break;
		hand.components.push_back({ in.at(0),in.at(2),in.at(4) });
	}

	for (int k = 0; k < hand.components.size(); k++) {
		robot1.addPart(hand.components.at(k));
		robot2.addPart(hand.components.at(k));
	}
	if (robot2.components.size() > robot1.components.size()) {
		robot2.printParts();
	}
	else {
		robot1.printParts();
	}
}