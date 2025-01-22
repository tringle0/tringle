#include <string>
#include <iostream>
#include <algorithm>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//2018-2019 Contest #2 Intermediate - Diff
//https://www.datafiles.acsl.org/samples/contest2/c2-int-prog.pdf

string commonAll(vector<string> strs){
	unordered_set<char> common;
	unordered_set<char> next;
	common.insert(strs.at(0).begin(), strs.at(0).end());
	for (int k = 1; k < strs.size(); k++) {
		next.clear();
		for (int i = 0; i < strs.at(k).length(); i++) {
			if (common.count(strs.at(k).at(i)) > 0) {
				next.insert(strs.at(k).at(i));
			}
		}
		common = next;
	}
	string result = "";
	unordered_set<char>::iterator itr;
	for (itr = common.begin(); itr != common.end(); itr++)
		result+= (*itr);
	sort(result.begin(),result.end());
	return result;
}

string diff(string a, string b) {
	string common = "";
	int bLoc = -1;
	unordered_map<char, deque<int>> bChars;
	for (int k = 0; k < b.length(); k++) {
		bChars[b.at(k)].push_back(k);
	}
	for (int k = 0; k < a.length(); k++) {
		if (!bChars[a.at(k)].empty()) {
			if (bChars[a.at(k)].back() < bLoc){
			}else{
				while (bChars[a.at(k)].front() < bLoc) bChars[a.at(k)].pop_front();
				if (bChars[a.at(k)].front() > bLoc) {
					bLoc = bChars[a.at(k)].front();
					common += b.at(bLoc);;
					bChars[a.at(k)].pop_front();
				}
			}	
		}
	}
	return common;
}

int main() {
	string a, b; cin >> a >> b;
	string revA = a, revB = b;
	reverse(revA.begin(), revA.end());
	reverse(revB.begin(), revB.end());
	string result = commonAll({ diff(a, b), diff(b, a), diff(revA, revB), diff(revB, revA) });
	if (result.length() == 0) {
		cout << "NONE";
	}
	else {
		cout << result;
	}
}