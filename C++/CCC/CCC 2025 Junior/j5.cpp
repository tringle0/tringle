#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

int getval(int k, int i, int c, int m) {
	return (k * c + i) % m + 1;
}

int main() {
	int r, c;
	cin >> r >> c;
	int m;
	cin >> m;
	struct tile {
		int r, c;
		int pathcost;
		int h;
	};

	struct heuristic {
		bool operator()(tile const& a, tile const& b) const {
			return a.h > b.h;
		}
	};

	queue<tile> bfs;
	for (int k = 0; k < c; k++) {
		bfs.push({ 0,k, getval(0,k,c,m), 0 });
	}

	int bestcost = 100000000;
	vector<vector<int>> dp(r, vector<int>(c,100000000));
	while (true) {
		if (bfs.empty()) break;
		tile current = bfs.front();
		bfs.pop();
		if (dp[current.r][current.c] < current.pathcost) continue;
		dp[current.r][current.c] = current.pathcost;
		if (current.r == r - 1) { bestcost = min(current.pathcost, bestcost); continue; }
		if (current.pathcost > bestcost) break;
		if (bfs.size() > 1500000) {
			cout << bestcost; return 0;
		}
		
		for (int k = -1; k <= 1; k++) {
			if (current.c + k >= 0 && current.c + k < c)
				bfs.push({ current.r + 1,current.c + k,current.pathcost + getval(current.r + 1,current.c + k,c,m)});
		}

	}
	cout << bestcost;
}