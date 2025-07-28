#include <iostream>
#include <vector>
#include <string>
using namespace std;

//CCC '25 S2 - Cryptogram Cracking Club
//https://dmoj.ca/problem/ccc25s2
//7-17-2025


int main() {
    string message; cin >> message; message += '/';
    long long n; cin >> n;

    vector<long long> nums;
    vector<char> letters;
    long long sum = 0;
    string currentNum = "";

    for (long long k = 0; k < message.length(); k++) {
        char c = message[k];
        if (isalpha(c)) {
            letters.push_back(c);
        }
        if (isalpha(c) || c == '/') {
            if (!currentNum.empty()) {
                long long num = stoll(currentNum);
                sum += num;
                nums.push_back(sum);
                currentNum = "";
            }
        } else {
            currentNum += c;
        }
    }

    n %= sum;
    for (long long k = 0; k < nums.size(); k++) {
        if (nums[k] >= n + 1) {
            cout << letters[k];
            break;
        }
    }
}