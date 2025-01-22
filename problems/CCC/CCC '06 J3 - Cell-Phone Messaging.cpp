#include <iostream>
#include <string>
using namespace std;

//CCC '06 J3 - Cell-Phone Messaging
//https://dmoj.ca/problem/ccc06j3/submit
//2025-01-21

int main() {
	while (true) {
		string in; cin >> in;
		int t = 0;
		if (in == "halt") break;
		for (int k = 0; k < in.length(); k++) {
			t += (in.at(k) - 'a') % 3;
			if (k > 1 && in.at(k) == in.at(k-1)) {
				t++;
			}
		}

		cout << t << endl;
	}
}