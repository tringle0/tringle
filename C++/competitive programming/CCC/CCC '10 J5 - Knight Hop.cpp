#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <math.h>
using namespace std;

//CCC '10 J5 - Knight Hop
//https://dmoj.ca/problem/ccc10j5
//11-24-2025

//using math
int main() {
	int x, y, tx, ty; cin >> x >> y >> tx >> ty;
	
	//relative distance required to cover
	int moveX = abs(tx - x);
	int moveY = abs(ty - y);

	//take larger distance to travel as primary distance
	int pr = max(moveX, moveY);
	int se = min(moveX, moveY);

	//number of 2-tile hops and 1-tile hops required to cover primary distance
	int prOnes = pr % 2;
	int prTwos = pr / 2;

	//repeat until the compliment of the primary distance travelled is enough to cover the secondary
	while (prOnes * 2 + prTwos < se) {
		//TWO MAIN TRANSFORMATIONS
		//A
		if (prTwos > 0) {
			//2 -> 1 1
			prTwos--;
			prOnes += 2;
		}
		//B
		else {
			//1 -> 1 2
			prTwos++;
		}
	}

	//get total steps
	int steps = prTwos + prOnes;

	//edge-cases
	if (pr == 1 && se == 0) cout << 3;
	else if (pr == 1 && se == 1) cout << 4;
	else if (pr == 2 && se == 2) cout << 4;
	else {
		//add a step if even/odd don't match up
		cout << steps + (prTwos % 2 == se % 2 ? 0 : 1);
	}
		
}