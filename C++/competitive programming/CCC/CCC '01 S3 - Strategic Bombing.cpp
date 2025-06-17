#include <iostream>  
#include <unordered_set>  
#include <unordered_map>  
#include <vector>  
using namespace std;  

// CCC '01 S3 - Strategic Bombing  
// https://dmoj.ca/problem/ccc01s3  
// 5-24-2025  

class roadsGraph {  
   struct road {  
       char p1, p2;  
       bool operator==(const road& other) const {  
           return (p1 == other.p1 && p2 == other.p2) || (p1 == other.p2 && p2 == other.p1);  
       }  
   };  

   struct roadHash {  
       size_t operator()(const road& r) const {  
           return hash<char>()(r.p1) ^ hash<char>()(r.p2);  
       }  
   };  

private:  
   vector<road> roads;  
   unordered_map<char, vector<char>> connections;  
   vector<vector<road>> validPaths;  

   void getConnections() {
       for (road r : roads) {
           connections[r.p1].push_back(r.p2);
           connections[r.p2].push_back(r.p1);
       }
       for (auto s : connections) {
           cout << s.first << ": ";
           for (auto t : s.second) {
               cout << t << " ";
           }
           cout << endl;
       }
   }  

   void traverseRec(char point, unordered_set<char> traversed, vector<road> path) {  
       // end condition  

       cout << point << endl;
       for (auto c : traversed) cout << c;
       cout << endl;
       if (point == 'B') {  
           for (auto s : path) {
               cout << s.p1;
           }
           cout << endl;
           validPaths.push_back(path);  
           return;  
       }  

       // go to next point  
       for (char c : connections[point]) {  
           if (traversed.count(c) == 0) {  
               traversed.insert(c);  
               path.push_back({point, c});  
               traverseRec(c, traversed, path);  
           }  
       }  
       return;  
   }  

public:  
   void addRoad(road r) {  
       roads.push_back(r);  
   }  

   void traverse() {  
       getConnections();  
       traverseRec('A', {}, {});  
   }  

   int checkPathCuts() {  
       int counter = 0;  
       for (road r : roads) {  
           int roadsCut = 0;
           for (auto s : validPaths) {  
               for (road r2 : s) {
                   if (r2 == r) continue;
               }
               roadsCut++;
           }  
           if (roadsCut == validPaths.size()) {
               cout << r.p1 << r.p2 << endl;
               counter++;
           }
       }  
       return counter;  
   }  
};  

int main() {  
   roadsGraph roads;  
   while (true) {  
       string input;
       char p1, p2;  
       cin >> input; p1 = input.at(0); p2 = input.at(1);
       if (p1 == '*' && p2 == '*') break;  
       roads.addRoad({p1, p2});  
   }  
  
   roads.traverse();  
   cout << roads.checkPathCuts() << endl;  
   return 0;  
}