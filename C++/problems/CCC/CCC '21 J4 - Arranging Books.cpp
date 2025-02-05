#include <iostream>
#include <string>
using namespace std;


//CCC '21 J4 - Arranging Books
//https://dmoj.ca/problem/ccc21j4
//1-12-2025

class shelf {
public:
	
	string books;
	int swaps = 0;
	shelf(string b) {
		books = b;
	}

	int rearrange() {
		int read = 0, mismatchPos = 0;

		int larges = 0, mediums = 0, smalls = 0;
		for (int k = 0; k < books.length(); k++) {
			if (books.at(k) == 'L') {
				larges++;
			}
			if (books.at(k) == 'M') {
				mediums++;
			}
			if (books.at(k) == 'S') {
				smalls++;
			}
		}
		int lastpos = books.length() - 1;
		//L swaps
		if (larges > 0 && (mediums > 0 || smalls > 0)) {
			while (mismatchPos < larges) {
				if (books.at(read) == 'L') {
					read++;
				}
				else {
					if (books.at(read) == 'M') {
						//find first L after amount of Ls and swap with M
						mismatchPos = read;
						read = larges;
						while (read < books.length()) {
							if (books.at(read) == 'L') {
								swap(mismatchPos, read);
								break;
							}
							read++;
						}
						read = mismatchPos;
					}
					else {
						//find last occurrence of L and swap with S
						mismatchPos = read;
						read = lastpos;
						while (read > mismatchPos) {
							if (books.at(read) == 'L') {
								swap(mismatchPos, read);
								break;
							}
							lastpos--;
							read--;
						}
						read = mismatchPos;
					}
				}

			}
		}
		lastpos = books.length() - 1;
		//M swaps
		if (mediums > 0 && smalls > 0) {
			while (mismatchPos < larges + mediums) {
				//swap S with last M
				if (books.at(read) == 'M') {
					read++;
				}
				else {
					mismatchPos = read;
					read = lastpos;
					while (read > mismatchPos) {
						if (books.at(read) == 'M') {
							swap(mismatchPos, read);
							break;
						}
						read--;
						lastpos--;
					}
					read = mismatchPos;
				}
			}
		}
		
		return swaps;
	}
private:
	void swap(int a, int b) {
		char temp = books.at(a);
		books.at(a) = books.at(b);
		books.at(b) = temp;
		swaps++;
	}
};


int main() {
	string input; cin >> input;
	shelf a(input);
	cout << a.rearrange();
}