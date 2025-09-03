#include <iostream>
#include <vector>
using namespace std;


int main() {
	
	int n; cin >> n;
	int currentArmLength = 2;
	int a, b;
	cin >> a >> b;

	int cr = n, cc = n;

	int k = 1;
	int currArmLength = 2;
	int cycles = 0;

	int ar, ac;
	int br, bc;

#define check if (k == a) {ar = cr; ac = cc;}if (k == b) {br = cr; bc = cc;}

	while (cycles < n) {
		//right
		for (int i = 0; i < currArmLength / 2; i++, k++, cc++) {
			check
		}
		//up
		for (int i = 0; i < currArmLength / 2; i++, k++, cr--) {
			check
		}
		currArmLength += 2;
		//left
		for (int i = 0; i < currArmLength / 2; i++, k++, cc--) {
			check
		}
		//down
		for (int i = 0; i < currArmLength / 2; i++, k++, cr++) {
			check
		}
		currArmLength += 2;
		cycles++;
	}
	//right
	for (int i = 0; i < currArmLength / 2; i++, k++, cc++) {
		check
	}
	cout << max(abs(ar - br), abs(ac - bc));
}