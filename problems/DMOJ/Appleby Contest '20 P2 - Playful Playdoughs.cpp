
//Appleby Contest '20 P2 - Playful Playdoughs
//https://dmoj.ca/problem/ac20p2

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	unordered_map<long long, long long> count;
	for (int k = 0; k < n; k++) {
		long long int input; cin >> input;
		count[input]++;
	}
	for (int k = 0; k < q; k++) {
		int num; int query; cin >> query >> num;
		long long split;
		switch (query) {
		case 1:
			split = count[num];
			count[num] = 0;
			if (num & 1) {
				count[num / 2] += split;
				count[num / 2 + 1] += split;
			}
			else {
				count[num / 2] += 2 * split;
			}
			break;
		case 2:
			cout << count[num] << endl;
			break;
		}
	}
}