#include <iostream>
using namespace std;

//CCC '08 S1 - It's Cold Here!
//https://dmoj.ca/problem/ccc08s1
//2-25-2025

int main() {
	struct city {
		string name; int temp;
	};
	city coldest, curr;
	while (true) {
		cin >> curr.name >> curr.temp;
		if (coldest.name.empty()) coldest = curr;
		if (curr.temp < coldest.temp) {
			coldest = curr; 
		}
		if (curr.name == "Waterloo") break;
	}
	cout << coldest.name;
}