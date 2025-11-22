#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

//CCC '09 S4 - Shop and Ship
//https://dmoj.ca/problem/ccc09s4
//11-20-2025

int main() {
	int n, t;
	cin >> n >> t;
	vector<vector<int>> routes(n, vector<int>(n, -1)); //-1 marks no link, cost
	struct pathTo {
		int city;
		int cost;
	};

	vector<int> costs; //city is index 

	for (int k = 0; k < t; k++) {
		int x, y, c;
		cin >> x >> y >> c;
		x--; y--;
		routes.at(x).at(y) = c;
		routes.at(y).at(x) = c;
	}

	int K;
	cin >> K;

	costs = vector<int>(n, -1);

	for (int k = 0; k < K; k++) {
		int z, c;
		cin >> z >> c;
		z--;
		costs.at(z) = c;
	}

	int targetCity;	
	cin >> targetCity;
	targetCity--;


	struct node {
		int city;
		int totalCost;

		void print() {
			cout << city << " " << totalCost << endl;
		}
	};

	struct nodeComparator {
		bool operator()(const node& a, const node& b) {
			return a.totalCost > b.totalCost;
		}
	};

	priority_queue<node, vector<node>, nodeComparator> BFS;
	vector<int> minCosts(n, INT_MAX);
	//add first
	BFS.push({ targetCity, 0});
	int minCost = INT_MAX; 
	
	while (!BFS.empty()) {
		//pick front
		node current = BFS.top();
		current.print();
		BFS.pop();

		//remove cases
		if (current.totalCost < minCosts.at(current.city)) {
			minCosts.at(current.city) = current.totalCost;
		}
		else {
			continue;
		}

		//case buy
		if (costs.at(current.city) != -1) {
			int buyCost = current.totalCost + costs.at(current.city);
			minCost = min(minCost, buyCost);
		}
		

		//case travel
		for (int k = 0; k < n; k++) {
			int pathCost = routes.at(k).at(current.city);
			if (pathCost != -1) {
				int nextCityTravelCost = current.totalCost + pathCost;
				BFS.push({ k, nextCityTravelCost });
			}
		}
	}

	cout << minCost;
	

}