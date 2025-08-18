#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//CCC '01 S3 - Strategic Bombing
//https://dmoj.ca/problem/ccc01s3
//8-16-2025

#define um unordered_map
#define us unordered_set
#define p pair



bool pathExistsRec(char currentNode, string cutPath, us<char> traversed, um<char, vector<char>> &adjList) {
	if (currentNode == 'B') return true;

	bool result = false;
	for (char c : adjList.at(currentNode)) {
		if (currentNode == cutPath.at(0) && c == cutPath.at(1)) continue;
		if (currentNode == cutPath.at(1) && c == cutPath.at(0)) continue;
		if (traversed.count(c) == 0) {
			us<char> nextTraverse = traversed;
			nextTraverse.insert(c);
			result |= pathExistsRec(c, cutPath, nextTraverse, adjList);
		}
	}
	return result;
}

int main() {
	um<char, vector<char>> adjList;
	vector<string> roads;
	while (true) {
		string input;
		cin >> input;
		if (input == "**") break;

		roads.push_back(input);
		adjList[input.at(1)].push_back(input.at(0));
		adjList[input.at(0)].push_back(input.at(1));
	}

	int counter = 0;
	for (string road : roads) {
		if (!pathExistsRec('A', road, {}, adjList)) {
			counter++;
			cout << road << endl;
		}
	}
	cout << "There are " << counter << " disconnecting roads." << endl;
}