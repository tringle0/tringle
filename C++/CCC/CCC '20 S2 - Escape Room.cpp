#include<iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//CCC '20 S2 - Escape Room
//https://dmoj.ca/problem/ccc20s2
//2-18-2025

int main() {
	int r, c; cin >> r >> c;
	struct pos {
		int r, c;
	};
	unordered_map<int, vector<pos>> graph;
	vector<vector<bool>> marked(r, vector<bool>(c, false));
	for (int k = 0; k < r; k++) {
		for (int i = 0; i < c; i++) {
			int in; cin >> in;
			graph[in].push_back({ k + 1,i + 1 });
		}
	}
	queue<pos> bfs;
	bfs.push({ r, c });
	while (true) {
		if (bfs.empty()) { cout << "no"; break; }
		pos current = bfs.front();
		bfs.pop();
		if (marked[current.r - 1][current.c - 1]) continue;
		marked[current.r - 1][current.c - 1] = true;

		if (current.c == 1 && current.r == 1) { cout << "yes"; break; }
		for (auto k : graph[current.r * current.c]) {
			bfs.push(k);
		}

	}


}