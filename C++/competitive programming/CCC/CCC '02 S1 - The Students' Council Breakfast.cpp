#include <iostream>
using namespace std;

int main() {
	int pink, green, red, orange;
	cin >> pink >> green >> red >> orange;
	int sum; cin >> sum;
	int counter = 0;
	int minimum = 100000;
	for (int p = 0; p <= sum; p++) {
		for (int g = 0; g <= sum; g++) {
			for (int r = 0; r <= sum; r++) {
				for (int o = 0; o <= sum; o++) {
					if (p * pink + g * green + r * red + o * orange == sum) {
						counter++;
						minimum = min(p + g + r + o, minimum);
						cout << "# of PINK is " << p << " # of GREEN is " << g << " # of RED is " << r << " # of ORANGE is " << o << endl;
					}	
				}
			}
		}
	}
	cout << "Total combinations is " << counter << ".\n";
	cout << "Minimum number of tickets to print is " << minimum << ".\n";

}