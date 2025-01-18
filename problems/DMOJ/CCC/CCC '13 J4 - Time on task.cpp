#include <iostream>
#include <vector>
using namespace std;

//CCC '13 J4 - Time on task
//https://dmoj.ca/problem/ccc13j4
//1-15-2025

vector<int> swap(vector<int>& list, int a, int b) {
	int temp = list.at(a);
	list.at(a) = list.at(b);
	list.at(b) = temp;
	return list;
}

vector<int> quicksort(vector<int>& list, int lower, int upper) {
	if (lower >= upper) return list;
	int i = lower;
	int pivot = list.at(upper);
	for (int k = lower; k < upper; k++) {
		if (list.at(k) < pivot) {
			swap(list, i, k);
			i++;
		}
	}
	swap(list, upper, i);
	int split = i;
	list = quicksort(list, lower, split - 1);
	list = quicksort(list, split + 1, upper);
	return list;
}

int main() {
	int n, t; cin >>t >>  n;
	vector<int> chores;
	for (int k = 0; k < n; k++) {
		int in; cin >> in; chores.push_back(in);
	}
	
	chores = quicksort(chores,0,chores.size()-1);
	int sum = 0; int counter = 0;
	for (int k = 0; k < chores.size(); k++) {
		sum += chores.at(k);
		if (sum > t) break;
		counter++;
	}
	cout << counter;
}