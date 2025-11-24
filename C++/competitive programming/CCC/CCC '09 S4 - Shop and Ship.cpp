#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

//CCC '09 S4 - Shop and Ship
//https://dmoj.ca/problem/ccc09s4
//tringle
//11-20-2025
//BFS-Dijkstra's approach for solving lowest cost in linked list problem


//struct for adjacency list to destination city and travel cost of a path
struct pathTo {
	int city;
	int cost;
};

/*
findBestPath function
	@brief this is the main algorithm in the code, runs BFS on the given graph
	@return the lowest-costing path from the destination to a selling-point, including the cost of selling
	@param[in] costs		vector containing the cost of buying at city at index
	@param[in] paths		adjacency matrix of paths representing the graph
	@param[in] targetCity	the destination city
*/
int findBestPath(vector<int> &costs, vector<vector<pathTo>> &paths, int &targetCity) {
	//each element of the bfs
	//holds the current city being checked and the cost of the route taken
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

	//BFS priority queue
	priority_queue<node, vector<node>, nodeComparator> BFS;

	//dp for lowest cost route to reach city at index
	vector<int> minCosts(costs.size(), INT_MAX);

	//current cost of best selling point
	int minCost = INT_MAX;

	//add first node to BFS
	BFS.push({ targetCity, 0 });


	//main BFS loop
	while (!BFS.empty()) {
		//pick front
		node current = BFS.top();
		BFS.pop();

		//update dp for current city
		if (current.totalCost < minCosts.at(current.city)) {
			minCosts.at(current.city) = current.totalCost;
		}
		else {
			//skip city if a better path to it already exists
			continue;
		}

		//if the city sells a pencil, check the total cost of buying it
		//update minCost if price is more worth
		if (costs.at(current.city) != -1) {
			int buyCost = current.totalCost + costs.at(current.city);
			minCost = min(minCost, buyCost);
		}

		//add neighbours to BFS using adjacency list
		//iterate through all paths in adjacency list
		for (pathTo path : paths.at(current.city)) {
			//cost of path
			int pathCost = path.cost;
			//total cost of travelling to the next city
			int nextCityTravelCost = current.totalCost + pathCost;

			//only add next node if the path to it is more worth than the currently found best cost
			if (nextCityTravelCost <= minCost)
				BFS.push({ path.city, nextCityTravelCost });
		}
	}

	//return the best cost that was found
	return minCost;
}


int main() {
	//makes input faster 
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr); 

	//GETTING PROBLEM INPUT
	//get input n and t, where n is amount of cities and t is amount of routes
	int n, t;
	cin >> n >> t;
	
	//adjacency list of paths (destination city, cost)
	vector<vector<pathTo>> paths(n); 

	//costs of buying in each city, -1 denotes cannot buy
	vector<int> costs(n, -1); 

	//input trade routes into adjacency matrix
	for (int k = 0; k < t; k++) {
		int x, y, c;
		cin >> x >> y >> c;
		x--; y--; //fix indexing
		paths.at(x).push_back({y,c});
		paths.at(y).push_back({x,c});
	}

	//amount of cities selling pencils
	int K;
	cin >> K;

	//input the cost c of pencil sold at city z
	for (int k = 0; k < K; k++) {
		int z, c;
		cin >> z >> c;
		z--; //fix indexing
		costs.at(z) = c;
	}

	//input destination city
	int targetCity;	
	cin >> targetCity;
	targetCity--; //fix indexing

	//run the function
	cout << findBestPath(costs, paths, targetCity);
}