#include <iostream>
#include <string>
using namespace std;

//CCC '17 J4 - Favourite Times
//https://dmoj.ca/problem/ccc17j4
//1-12-2025

bool checktime(int hr, int m) {
	string time = to_string(hr) + (m > 9 ? "" : "0") + to_string(m);
	if (time.at(1) - time.at(0) != time.at(2) - time.at(1)) return false;
	if(hr>9){
		if (time.at(1) - time.at(0) != time.at(3) - time.at(2)) return false;
	}
	return true;
}

int main() {
	int n; cin >> n; n++;
	int hr, m;
	int counter = 31*((int)n / 720);
	for (int k = 0; k < n%720; k++) {
		hr = (11 + (k / 60) % 12)%12+1;
		m = k % 60;
		if (checktime(hr, m)) {
			counter++;
		}
	}
	cout << counter;
}