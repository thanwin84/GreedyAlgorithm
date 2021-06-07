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
	int test_case;
	cin >> test_case;
	while (test_case--) {
		int n;
		cin >> n;
		vector<int> arr;
		int data;
		for (int i = 0; i < n; i++) {
			cin >> data;
			arr.push_back(data);
		}
		sort(arr.begin(), arr.end(), greater<int>());
		int count_one = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (arr[i] == 1) {
				count_one++;
				cout << "1 ";
			}
			else if (arr[i] > 1) {
				break;
			}
		}
		if (n - count_one == 2 and arr[0] == 3 and arr[1] == 2) {
			cout << "2 3" << endl;
		}
		else {
			for (int i = 0; i < n - count_one; i++) {
				cout << arr[i] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
