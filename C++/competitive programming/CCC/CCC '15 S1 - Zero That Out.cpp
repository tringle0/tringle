#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//CCC '15 S1 - Zero That Out
//https://dmoj.ca/problem/ccc15s1
//7-29-2025

int main() {
	int n; cin >> n;
	int sum = 0;
	stack<int> nums;
	for (int k = 0; k < n; k++) {
		int input; cin >> input;
		if (input == 0) {
			sum -= nums.top();
			nums.pop();
		}
		else {
			sum += input;
			nums.push(input);
		}
	}
	cout << sum;
}