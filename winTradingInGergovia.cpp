#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
#include<unordered_map>
#include<string>
#define int long long int
using namespace std;
void solve() {
	int n;
	cin >> n;
	while (true) {
		vector<int> arr;
		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
			arr.push_back(p);
		}
		vector<pair<int, int>> buy;
		vector<pair<int, int>> sell;
		for (int i = 0; i < n; i++) {
			if (arr[i] > 0) buy.push_back({ arr[i], i });
			else sell.push_back({arr[i], i});
		}
		int work = 0;
		int i = 0;
		int j = 0;
		while (i < buy.size() and j < sell.size()) {
			int x = min(buy[i].first, -sell[j].first);
			buy[i].first -= x;
			sell[j].first += x;
			work += x *abs(buy[i].second - sell[j].second);
			int work = (abs(buy[i].second - sell[j].second) * x);
			if (buy[i].first == 0) i++;
			if (sell[j].first == 0) j++;
		}
		cout << work << endl;
		cin >> n;
		if (n == 0) break;
		
	}
	
	
}
int32_t main() {
	
	solve();
	return 0;

}
