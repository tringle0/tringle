#include <iostream>
#include <queue>
using namespace std;

//CCC '20 S1 - Surmising a Sprinter's Speed
//https://dmoj.ca/problem/ccc20s1
//2-25-2025

int main() {
	int n; cin >> n;
	struct point {
		double time, distance;
	};
	struct comparator {
		bool operator()(point const& a, point const& b) const {
			return a.time > b.time;
		}
	};
	priority_queue<point, vector<point>, comparator> timeline;

	for (int k = 0; k < n; k++) {
		point in;
		cin >> in.time >> in.distance;
		timeline.push(in);
	}

	double minspd = 0;
	point last, curr = timeline.top(); timeline.pop();
	while (!timeline.empty()) {
		double currspd;
		last = curr;
		curr = timeline.top();
		timeline.pop();
		currspd = abs(curr.distance - last.distance) / (curr.time - last.time);
		minspd = max(currspd, minspd);
	}
	cout << minspd;

}
