#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//CCC '08 J4 - From Prefix to Postfix
//https://dmoj.ca/problem/ccc08j4
//1-12-2025

class preToPost {
public:
	string equation;
	unordered_map<char, string> vars;

	preToPost(string e) {
		equation = e;
	}

	bool isOperator(int pos) {
		return equation.at(pos) == '+' || equation.at(pos) == '-';
	}

	string expand(string current) {
		string result = "";
		int offset = 0;
		for (int k = current.length() - 1; k >= 0;  k--) {
			if (vars.count(current.at(k)) == 0) {
				result = current.at(k) + result;
			}
			else {
				result = expand(vars[current.at(k)]) + result;
			}
		}
		return result;
	}

	string result() {
		//shorten
		char currentVar = 'a';
		int read = equation.length() - 1;
		while (read >= 0) {
			//find operator and then two values to replace as a var
			if (isOperator(read) && !isOperator(read+1) && !isOperator(read+2)) {
				vars[currentVar] = equation.substr(read+1,2) + equation.at(read);
				equation.erase(equation.begin() + read, equation.begin() + read + 3);
				equation.insert(equation.begin() + read, currentVar);
				currentVar++;
				read++;
			}
			read--;
		}
		currentVar--;
		string strVar(1, currentVar);
		equation = expand(strVar);
		string result(1,equation.at(0));
		for (int k = 1; k < equation.length(); k++) {
			result += " ";
			result += equation.at(k);
		}

		return result;
	}
};

int main() {
	while (true) {
		string input, spaceless; getline(cin, input);
		if (input == "0") break;
		for (int k = 0; k < input.length(); k++) {
			if (input.at(k) != ' ') {
				spaceless += input.at(k);
			}
		}
		if (input.length() == 1) {
			cout << input << endl;
		}
		else {
			cout << preToPost(spaceless).result() << endl;
		}	
	}
	
}