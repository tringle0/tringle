#include <iostream>
#include <math.h>
using namespace std;

//CCC '09 S1 - Cool Numbers
//https://dmoj.ca/problem/ccc09s1
//2-24-2025

int main() {
	int start, end;
	cin >> start >> end;
	int counter = 0;
	for (int k = ceil(cbrt(start)); k <= floor(cbrt(end)); k++) {
		if (sqrt(k * k * k) == (int)sqrt(k * k * k)) {
			counter++;
		}
	}
	cout << counter;
}