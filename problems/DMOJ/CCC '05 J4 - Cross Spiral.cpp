#include <iostream>
#include <vector>
using namespace std;

//CCC '05 J4 - Cross Spiral
//https://dmoj.ca/problem/ccc05j4

struct vec2 {
	int x, y;
};

class board {
public:
	vector<vector<int>> vec;
	int width, height;
	int cwidth, cheight;
	int steps = 0;
	int dir = 0;

	vector<vec2> directions = { { 1,0 }, { 0,1 } , { -1,0 }, { 0,-1 } };

	board(int w, int h, int cutw, int cuth, int s) {
		vec = vector<vector<int>>(h, vector<int>(w, 0));
		steps = s;
		width = w; height = h; cwidth = cutw; cheight = cuth;
		for (int k = 0; k < cuth; k++) {
			for (int i = 0; i < cutw; i++) {
				vec[k][i] = 1; //topleft
				vec[k][width - cutw + i] = 1; //topright
				vec[height - cuth + k][i] = 1; //bottomleft
				vec[height - cuth + k][width - cutw + i] = 1; //bottomright
			}
		}
	}

	void print() {
		for (int k = 0; k < vec.size(); k++) {
			for (int i = 0; i < vec.at(0).size(); i++) {
				cout << vec[k][i] << " ";
			}
			cout << endl;
		}
	}

	void traverse() {
		vec2 pos = { cwidth ,0 };
		vec2 lastpos;
		for(int k = 0; k < steps; k++){
			lastpos = pos;
			pos = walk(pos, directions.at(dir % 4), directions.at((dir + 1) % 4),0);
			if (lastpos.x == pos.x && lastpos.y == pos.y) {
				break;
			}
		}
		cout << pos.x + 1<< endl << pos.y + 1;
	}

private:
	bool inbounds(vec2 pos) {

		if (pos.x > vec[0].size()-1) return false;
		if (pos.x < 0)  return false;
		if (pos.y > vec.size()-1)  return false;
		if (pos.y < 0)  return false;
		return true;
	}

	vec2 walk(vec2 pos, vec2 primary, vec2 secondary, int turns) {
		//mark current tile
		vec[pos.y][pos.x] = 1;
		vec2 nexttile = { pos.x + primary.x, pos.y + primary.y };
		bool checkpbounds = inbounds(nexttile);
		switch(checkpbounds) {
		case true:
			if (vec.at(pos.y + primary.y).at(pos.x + primary.x) == 0) {
				pos.x += primary.x;
				pos.y += primary.y;
				break;
			}
		case false:
			nexttile = { pos.x + secondary.x, pos.y + secondary.y };
			bool checksbounds = inbounds(nexttile);
			switch (checksbounds) {
			case true:
				if (vec.at(pos.y + secondary.y).at(pos.x + secondary.x) == 0) {
					pos.x += secondary.x;
					pos.y += secondary.y;
					break;
				}
			case false:
				dir++;
				//check if stuck
				if (turns == 3) {
					return pos;
				}
				return walk(pos, directions.at(dir % 4), directions.at((dir + 1) % 4), turns+1);
			}
		}
		return pos;
	}
	

};

int main() {
	int w, h, cutw, cuth, steps;
	cin >> w >> h >> cutw >> cuth >> steps;
	board a(w, h, cutw, cuth, steps);
	a.traverse();
}