#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
	int n, c, p;
	cin >> n >> c >> p;
	cout << (c * p >= n ? "yes" : "no");
}