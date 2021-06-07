#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
#include<unordered_map>
#include<string>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int w, h, n;
		cin >> w >> h >> n;
		vector<int> x_coordinates;
		vector<int> y_coordinates;
		x_coordinates.push_back(0);
		y_coordinates.push_back(0);
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			x_coordinates.push_back(x);
			y_coordinates.push_back(y);
		}
		x_coordinates.push_back(w + 1);
		y_coordinates.push_back(h + 1);
		sort(x_coordinates.begin(), x_coordinates.end());
		sort(y_coordinates.begin(), y_coordinates.end());
		int max_width = 0;
		for (int i = 0; i < x_coordinates.size()-1; i++) {
			max_width = max(max_width, abs(x_coordinates[i] - x_coordinates[i+1]) - 1);
		}
		int max_h = 0;
		for (int i = 0; i < y_coordinates.size() - 1; i++) {
			max_h = max(max_h, abs(y_coordinates[i] - y_coordinates[i+1])-1);
		}
		cout << max_width * max_h << endl;

	}
	return 0;
}
