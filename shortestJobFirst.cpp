#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
using namespace std;
struct Job {
	int id;
	int arrival_time;
	int burst_time;
	Job(int id, int arrival_time, int burst_time) {
		this->id = id;
		this->arrival_time = arrival_time;
		this->burst_time = burst_time;
	}
	
};
bool comp(Job p1, Job p2) {
	if (p1.arrival_time == p2.arrival_time) {
		if (p1.burst_time == p2.burst_time) {
			return p1.id < p2.id;
		}
		else {
			return p1.burst_time < p2.burst_time;
		}
	}
	else {
		return p1.arrival_time < p2.arrival_time;
	}
}
auto com = [](Job p1, Job p2) {
	return p1.burst_time > p2.burst_time;
};
vector<int> shortestJobFirst(vector<int> id, vector<int> arrival_times, vector<int> burst_times) {
	vector<Job> schedules;
	for (int i = 0; i < arrival_times.size(); i++) {
		schedules.push_back(Job(id[i], arrival_times[i], burst_times[i]));
	}
	sort(schedules.begin(), schedules.end(), comp);
	vector<int> result;
	priority_queue <Job, vector<Job>, decltype(com)> ReadyQueue(com);
	ReadyQueue.push(schedules[0]);
	int n = id.size();
	int i = 1;
	int currentTime = 0;
	while (!ReadyQueue.empty()) {
		Job top = ReadyQueue.top();
		ReadyQueue.pop();
		result.push_back(top.id);
		currentTime += top.burst_time;
		while (i < n and schedules[i].arrival_time <= currentTime) {
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
