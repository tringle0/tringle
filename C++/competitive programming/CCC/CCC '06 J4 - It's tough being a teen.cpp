#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//CCC '06 J4 - It's tough being a teen
//https://dmoj.ca/problem/ccc06j4
//5-12-2025

class completeTasks {
private:
	unordered_map<int, vector<int>> priorities; //task, requirements
	vector<int> answer;

public:

	completeTasks() {
		priorities = { {4,{1,3}},{7,{1}},{1,{2}},{5,{3}} };
	}

	void addPriority(int task, int requirement) {
		priorities[task].push_back(requirement);
	}

	vector<int> getAnswer() {
		return answer;
	}

	bool doTasks() {
		bool result = false;
		unordered_set<int> todo = { 1,2,3,4,5,6,7 };
		for (int k = 1; k <= 7; k++) {
			result |= doTasksRec(k, todo, {});
			if (result) break;
		}
		return result;
	}

	bool doTasksRec(int task, unordered_set<int> todo, vector<int> order) {

		//check if task is valid
		for (int k : priorities[task]) {
			if (todo.count(k) != 0) return false;
		}
		order.push_back(task);
		todo.erase(task);

		//check if finished
		if (todo.empty()) {
			answer = order;
			return true;
		}
		//check next tasks
		bool result = false;
		for (int k = 1; k <= 7; k++) {
			if(todo.count(k) != 0)
			result |= doTasksRec(k, todo, order);
			if (result) break;
		}
		return result;
	}


};

int main() {
	completeTasks tasks = completeTasks();
	while (true) {
		int task, requirements;
		cin >> requirements >> task;
		if (task == 0 && requirements == 0) break;
		tasks.addPriority(task, requirements);
	}
	if (tasks.doTasks()) {
		vector<int> ans = tasks.getAnswer();
		for (int k = 0; k < ans.size()-1; k++) {
			cout << ans.at(k) << " ";
		}
		cout << ans.at(ans.size() - 1);
	}
	else {
		cout << "Cannot complete these tasks. Going to bed.";
	}

}