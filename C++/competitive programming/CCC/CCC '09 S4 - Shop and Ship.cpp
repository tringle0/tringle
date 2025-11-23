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
	//makes input faster 
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr); 

	int n, t;
	cin >> n >> t;
	
	struct pathTo {
		int city;
		int cost;
	};
	vector<vector<pathTo>> paths(n); //adjacency list of paths(city,cost)
	vector<int> costs(n, -1); //city is index 

	for (int k = 0; k < t; k++) {
		int x, y, c;
		cin >> x >> y >> c;
		x--; y--; //fix indexing
		paths.at(x).push_back({y,c});
		paths.at(y).push_back({x,c});
	}

	int K;
	cin >> K;

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


	//comparator for priority queue
	struct nodeComparator {
		bool operator()(const node& a, const node& b) {
			return a.totalCost > b.totalCost;
		}
	};

	priority_queue<node, vector<node>, nodeComparator> BFS;
	vector<int> minCosts(n, INT_MAX);  //lowest cost path to city at index
	//add first
	BFS.push({ targetCity, 0});
	int minCost = INT_MAX; 
	
	while (!BFS.empty()) {
		//pick front
		node current = BFS.top();
		//current.print();
		BFS.pop();

		//update best path to reach a certain city
		if (current.totalCost < minCosts.at(current.city)) {
			minCosts.at(current.city) = current.totalCost;
		}
		else {
			//skip city if a better path to it already exists
			continue;
		}

		//case buy
		if (costs.at(current.city) != -1) {
			int buyCost = current.totalCost + costs.at(current.city);
			minCost = min(minCost, buyCost);
		}
		
		//case travel
		for (pathTo path : paths.at(current.city)) {
			int pathCost = path.cost;
			int nextCityTravelCost = current.totalCost + pathCost;

			//only add next node if the path to it is more worth than the best cost currently
			if(nextCityTravelCost <= minCost)
				BFS.push({ path.city, nextCityTravelCost });
		}
	}

	cout << minCost;
	
}