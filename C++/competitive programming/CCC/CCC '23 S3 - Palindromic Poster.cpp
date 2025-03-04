#include <iostream>
#include <vector>
using namespace std;

//CCC '23 S3 - Palindromic Poster
//https://dmoj.ca/problem/ccc23s3
//2-6-2025

#define allow 'o'
#define block 'x'
#define blockall 'b'

int main() {
	int m, n, r, c;
	cin >> n >> m >> r >> c;

	if (r == n && c == m) {
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < m; i++) {
				cout << 'h';
			}
			cout << '\n';
		}
		return 0;
	}
	if (r > n || c > m) {
		cout << "IMPOSSIBLE";
		return 0;
	}

	if (r == n && m % 2 == 0 && c % 2 == 1) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	if (c == m && n % 2 == 0 && r % 2 == 1) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < m; i++) {
			if (k == 0 && i == 0) {
				if (c == 0 && r == 0) {
					cout << blockall;
				}
				else {
					cout << block;
				}
				
				continue;
			}
			if (k != 0 && i != 0) {
				cout << allow;
				continue;
			}
			//top row
			if (k == 0) {
				//forced palindome top row (when all r = n)
				if (r == n) {
					//odd # of collumns: odd palindrome
					if (m % 2 == 1) {
						//even amount of required cols: fill center
						if (c % 2 == 0) {
							//fill center tile
							if (i == m / 2) {
								cout << block;
							}
							else {
								//fill rest of the tiles from left and right
								int fromcenter = c / 2;
								if (i < m / 2 - fromcenter || i > m / 2 + fromcenter) {
									cout << block;
								}
								else {
									cout << allow;
								}
							}
						}
						else {
							//odd amount required cols: dont fill center
							int fromcenter = c / 2;
							if (i < m / 2 - fromcenter || i > m / 2 + fromcenter) {
								cout << block;
							}
							else {
								cout << allow;
							}
						}
					}
					else {
						//even amount of columns rows: even palindrome
						if (c % 2 == 0) {
							//fill from left and right
							int fromcenter = (m - c) / 2;
							if (i < m / 2 - fromcenter || i >= m / 2 + fromcenter) {
								cout << block;
							}
							else {
								cout << allow;
							}
						}
					}
				}
				else {
					//not forced: top row doesn't have to be palindrome
					if (i < m - c) {
						cout << block;
					}
					else {
						cout << allow;
					}
				}
			}
			//leftmost column
			if (i == 0) {
				//forced palindome left column (when all c = m)
				if (c == m) {
					//odd # of rows: odd palindrome
					if (n % 2 == 1) {
						//even amount of required rows: fill center
						if (r % 2 == 0) {
							//fill center tile
							if (k == n / 2) {
								cout << block;
							}
							else {
								//fill rest of the tiles from top and bottom
								int fromcenter = r / 2;
								if (k < n / 2 - fromcenter || k > n / 2 + fromcenter) {
									cout << block;
								}
								else {
									cout << allow;
								}
							}
						}
						else {
							//odd amount required rows: dont fill center
							int fromcenter = r / 2;
							if (k < n / 2 - fromcenter || k > n / 2 + fromcenter) {
								cout << block;
							}
							else {
								cout << allow;
							}
						}
					}
					else {
						//even amount of rows: even palindrome
						if (r % 2 == 0) {
							//fill from top and bottom
							int fromcenter = (n - r) / 2;
							if (k < n / 2 - fromcenter || k >= n / 2 + fromcenter) {
								cout << block;
							}
							else {
								cout << allow;
							}
						}
					}
				}
				else {
					//not forced: leftmost col doesn't have to be palindrome
					if (k < n - r) {
						cout << block;
					}
					else {
						cout << allow;
					}
				}
			}
		}
		cout << '\n';
	}


}