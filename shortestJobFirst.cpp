//sort according to arrival time, if arrival time is equal sort according burst time and if both equal sort by id
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
using namespace std;
struct Pair {
	int id;
	int arrivalT;
	int burstT;
	Pair(int id, int arrivalT, int burstT) {
		this->id = id;
		this->arrivalT = arrivalT;
		this->burstT = burstT;
	}
	
};
bool comp(Pair p1, Pair p2) {
	if (p1.arrivalT == p2.arrivalT) {
		if (p1.burstT == p2.burstT) {
			return p1.id < p2.id;
		}
		else {
			return p1.burstT < p2.burstT;
		}
	}
	else {
		return p1.arrivalT < p2.arrivalT;
	}
}
auto com = [](Pair p1, Pair p2) {
	return p1.burstT > p2.burstT;
};
vector<int> shortestJobFirst(vector<int> id, vector<int> arrival, vector<int> burst) {
	vector<Pair> schedules;
	for (int i = 0; i < arrival.size(); i++) {
		schedules.push_back(Pair(id[i], arrival[i], burst[i]));
	}
	sort(schedules.begin(), schedules.end(), comp);
	vector<int> result;
	priority_queue <Pair, vector<Pair>, decltype(com)> ReadyQueue(com);
  //start from time 0
  //push first process into ready queue and check if any process come when first process is busy
  //push all process before the proccess time
	ReadyQueue.push(schedules[0]);
	int n = id.size();
	int i = 1;
	int currentTime = 0;
	while (!ReadyQueue.empty()) {
		Pair top = ReadyQueue.top();
		ReadyQueue.pop();
		result.push_back(top.id);
		currentTime += top.burstT;
		while (i < n and schedules[i].arrivalT <= currentTime) {
			ReadyQueue.push(schedules[i]);
			i++;
		}
	}
	
	return result;
}

int main() {
	vector<int> id = { 1, 2, 3, 4 };
	vector<int> arri = { 2, 0, 4, 5 };
	vector<int> burst = { 3, 4, 2, 4 };
	vector<int> result = shortestJobFirst(id, arri, burst);
	for (auto i : result) {
		cout << i << " ";
	}
	
    
	
	return 0;
}
