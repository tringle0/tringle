#include <iostream>
#include <vector>
using namespace std;

// quicksort algorithm
// 1/8/2025

void printvec(vector<int>& list) {
	for (int k = 0; k < list.size(); k++) {
		cout << list.at(k) << endl;
	}
}

vector<int> swap(vector<int>& list, int a, int b) {
	int temp = 0;
	temp = list.at(a);
	list.at(a) = list.at(b);
	list.at(b) = temp;
	return list;
}

vector<int> quicksort(vector<  int>& list, int lower, int upper) {
	if (upper <= lower) return list;
	int pivot = list.at(upper);
	int i = lower;
	for (int k = lower; k < upper; k++) {
		if (list.at(k) < list.at(upper)) {
			list = swap(list, k, i);
			i++;
		}
	}

	list = swap(list, i, upper);

	//partition
	int split = i;
	list = quicksort(list, lower, split - 1);
	list = quicksort(list, split + 1, upper);
	return list;
}

int main() {
	vector<int> list;
	int n; cin >> n;
	for (int k = 0; k < n; k++) {
		int input; cin >> input;
		list.push_back(input);
	}
	list = quicksort(list, 0, list.size() - 1);
	printvec(list);
}
