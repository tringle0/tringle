#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//CCC '17 S2 - High Tide, Low Tide
//https://dmoj.ca/problem/ccc17s2
//1-14-2025

vector<int> swap(int& a, int& b, vector<int> vec) {
	int temp = vec.at(a);
	vec.at(a) = vec.at(b);
	vec.at(b) = temp;
	return vec;
}

vector<int> quicksort(vector<int> vec, int lower, int upper) {
	if (upper <= lower) return vec;
	int pivot = vec.at(upper);
	int i = lower;
	for (int k = lower; k < upper; k++) {
		if (vec.at(k) < pivot) {
			vec = swap(k, i, vec);
			i++;
		}
	}
	vec = swap(i, upper, vec);

	int split = i;
	vec = quicksort(vec, lower, split - 1);
	vec = quicksort(vec, split + 1, upper);
	return vec;

}

int main() {
	int n; cin >> n;
	vector<int> tides;
	for (int k = 0; k < n; k++) {
		int input; cin >> input; tides.push_back(input);
	}
	tides = quicksort(tides, 0, tides.size() - 1);
	int split = ceil(tides.size() / 2);

	if (tides.size() & 1) {
		for (int k = 0; k < split; k++) {
			cout << tides.at(split - k) << " " << tides.at(split + k + 1) << " ";
		}
		cout << tides.at(0) << " ";
	}else{
		for (int k = 0; k < split; k++) {
			cout << tides.at(split - 1 - k) << " " << tides.at(split + k) << " ";
		}
	}
}