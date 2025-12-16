#include <iostream>
#include <unordered_map>

//CCC '12 S3 - Absolutely Acidic
//https://dmoj.ca/problem/ccc12s3
//12-12-2025
using namespace std;

int main() {
    int n; cin >> n;
    unordered_map<int, int> counts;
    int mostFreq = INT_MIN, secFreq = INT_MIN;

    for (int k = 0; k < n; k++) {
        int in; cin >> in;
        counts[in]++;
    }

    for (auto k : counts) {
        mostFreq = max(mostFreq, k.second);
    }

    for (auto k : counts) {
        if (k.second < mostFreq) secFreq = max(secFreq, k.second);
    }

    pair<int, int> mostFreqN = { INT_MAX, INT_MIN };
    pair<int, int> secFreqN = { INT_MAX, INT_MIN };

    for (auto k : counts) {
        if (k.second == mostFreq) {
            mostFreqN.first = min(mostFreqN.first, k.first);
            mostFreqN.second = max(mostFreqN.second, k.first);
        }
        if (k.second == secFreq) {
            secFreqN.first = min(secFreqN.first, k.first);
            secFreqN.second = max(secFreqN.second, k.first);

        }
    }

    if (mostFreqN.first != mostFreqN.second) cout << abs(mostFreqN.first - mostFreqN.second);
    else {
        cout << max(abs(mostFreqN.first - secFreqN.first), abs(mostFreqN.first - secFreqN.second));
    }

}