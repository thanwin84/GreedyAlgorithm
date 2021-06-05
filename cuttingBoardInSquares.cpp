//if we want to cut vertical line, we have to bring all horizontal together
//if we want to cut horizontal line, we have to bring all vertical line together
//problem name on spoj is chocholate
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
using namespace std;
bool comp(int a, int b) {
	return a > b;
}
int boardCutting(vector<int> cost_y, vector<int> cost_x) {
	sort(cost_y.begin(), cost_y.end(), comp);
	sort(cost_x.begin(), cost_x.end(), comp);
	int horizontal = 1;
	int vertical = 1;
	int cost = 0;
	int i = 0;
	int j = 0;
	while (i < cost_y.size() and j < cost_x.size()) {
		if (cost_y[i] >= cost_x[j]) {
    //vertical cutting
			cost += (vertical * cost_y[i]);
			horizontal++;
			i++;
		}
		else {
    //horizontal cutting
			cost += (horizontal * cost_x[j]);
			vertical += 1;
			j++;
		}
	}
	while (i < cost_y.size()) {
		cost += (vertical * cost_y[i]);
		horizontal++;
		i++;
	}
	while (j < cost_x.size()) {
		cost += (horizontal * cost_x[j]);
		vertical += 1;
		j++;
	}
	return cost;
}

int main() {
	vector<int> cost_y = { 2, 1, 3, 1, 4 };
	vector<int> cost_x = { 4, 1, 2 };
	int testCase;
	cin >> testCase;
	cout << endl;
	while (testCase--) {
		int n, m;
		cin >> n >> m;
		n--;
		m--;
		vector<int>cost_x;
		vector<int> cost_y;
		int p;
		for (int i = 0; i < n; i++) {
			cin >> p;
			cost_x.push_back(p);
		}
		for (int i = 0; i < m; i++) {
			cin >> p;
			cost_y.push_back(p);
		}
		cout << boardCutting(cost_y, cost_x) << endl;
	}
	return 0;
}
