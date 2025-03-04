#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
	int n; cin >> n;
	int curr = 0;
	int last = 0;
	int longest = 0;
	bool foundP = false;
	for (int k = 0; k < n; k++) {
		char in; cin >> in;
		if (in == 'P') {
			foundP = true;
			last = curr;
			curr = 0;
		}
		else {
			curr++;
		}
		longest = max(longest, last + curr + 1);
	}
	cout << longest - (!foundP?2:0);
}