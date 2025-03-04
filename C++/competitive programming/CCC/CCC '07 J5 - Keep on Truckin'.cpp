#include <iostream>
#include <vector>

using namespace std;

//CCC '07 J5 - Keep on Truckin'
//https://dmoj.ca/problem/ccc07j5
//2-12-2025

int main() {
	vector<long int> init = { 0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000 };
	
	int mind, maxd; cin >> mind >> maxd;

	int n; cin >> n;
	for (int k = 0; k < n; k++) {
		long int input; cin >> input;
		long int i;
		for (i = 0; init.at(i) < input; i++);
		init.insert(init.begin() + i, input);
	}
	vector<long int> p(init.size());
	p.at(0) = 1;
	for (int k = 1; k < p.size(); k++) {
		long int currentpos = k-1;
		long int sum = 0;
		while (currentpos >= 0) {
			if(init.at(k) - init.at(currentpos) <= maxd && init.at(k) - init.at(currentpos) >= mind)
			sum += p.at(currentpos);
			currentpos--;
		}
		p.at(k) = sum;
	}
	cout << p.back() << '\n';
}