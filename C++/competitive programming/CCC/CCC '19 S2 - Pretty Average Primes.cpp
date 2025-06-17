#include <iostream>
using namespace std;

//CCC '19 S2 - Pretty Average Primes
//https://dmoj.ca/problem/ccc19s2
//6-17-2025

bool isPrime(int n) {
	if (n <= 1) return false;
	int counter = 0;
	for (int k = 2; k*k <= n; k++) {
		if (n % k == 0) counter++;
	}
	return !(counter > 0);
}

int main() {
	int n; cin >> n;
	for (int k = 0; k < n; k++) {
		int in; cin >> in;
		for (int k = 2; k <= in * 2; k++) {
			if (isPrime(k) && isPrime(in*2-k)) {
				cout << k << " " << in * 2 - k << endl; break;
			}
		}
	}
}