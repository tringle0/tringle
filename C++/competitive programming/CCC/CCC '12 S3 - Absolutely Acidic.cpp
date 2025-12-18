#include <iostream>
#include <vector>
#include <climits>

//CCC '12 S3 - Absolutely Acidic
//https://dmoj.ca/problem/ccc12s3
//tringle
//12-18-2025
//One pass solution to find most frequent and second most frequent readings
using namespace std;

//single pass solution
int main() {
    int n; cin >> n;
    vector<int> counts(1001, 0);
    
    //input
    for (int k = 0; k < n; k++) {
        int in; cin >> in;
        counts[in]++;
    }

    //frequencies
    int mostFreq = 0, secFreq = 0;

    //pair of min and max value
    pair<int, int> mostFreqV = {INT_MAX, 0};
    pair<int, int> secFreqV = {INT_MAX, 0};
    for (int k = 0; k < 1001; k++) {
        int freq = counts.at(k); 
        int value = k;
        if (freq < secFreq) continue;
        //greater than most frequent, shift down to sec most frequent
        if (freq > mostFreq) {
            secFreq = mostFreq;
            mostFreq = freq;

            secFreqV = mostFreqV;
            mostFreqV = { value, value };
        }
        //equal to most frequent, see if larger/smaller than limits
        else if (freq == mostFreq) {
            mostFreqV = { min(value, mostFreqV.first), max(value, mostFreqV.second) };
        }
        //greater-equal to second most frequent, replace and find new limits
        else if (freq >= secFreq) {
            secFreq = freq;
            secFreqV = { min(value, secFreqV.first), max(value, secFreqV.second) };
        }
    }

    //most freq max = min, only one most freq number
    if (mostFreqV.first == mostFreqV.second) {
        cout << max(abs(mostFreqV.first - secFreqV.first), abs(mostFreqV.first - secFreqV.second));
    }
    //multiple most freq numbers, find difference between min and max
    else {
        cout << abs(mostFreqV.first - mostFreqV.second);
    }
}