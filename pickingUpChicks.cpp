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
void minSwap(vector<int> x_coordinates, vector<int> velocity, int n, int B, int k, int T, int j) {
	int count = 0;
	int swaps = 0;
	int not_possible = 0;
	for (int i = n - 1; i >= 0; i--) {
		int distance_needed = B - x_coordinates[i];
		int distance_possible = velocity[i] * T;
		if (distance_possible >= distance_needed) {
			count++;
			if (not_possible > 0) swaps += not_possible;
		}
		else not_possible++;
		if (count >= k) break;
	}
	if (count >= k) {
		cout << "Case #" << j << ": " << swaps << endl;
	}
	else {
		cout << "Case #" << j << ": " << "IMPOSSIBLE" << endl;
	}
}
int32_t main() {
	int t;
	cin >> t;
	int j = 1;
	while (t--) {
		int n, k, B, T;
		cin >> n >> k >> B >> T;
		vector<int> x_coordinates;
		int p;
		for (int i = 0; i < n; i++) {
			cin >> p;
			x_coordinates.push_back(p);
		}
		vector<int> velocity;
		for (int i = 0; i < n; i++) {
			cin >> p;
			velocity.push_back(p);
		}
		minSwap(x_coordinates, velocity, n, B, k, T, j);
		j++;
	}
	return 0;

}
