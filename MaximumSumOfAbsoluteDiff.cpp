//time: O(nlogn) and space: O(n)
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
using namespace std;
int maxAbsoluteDiff(vector<int> arr) {
	sort(arr.begin(), arr.end());
	int i = 0;
	int j = arr.size() - 1;
	vector<int> finalSequence;
	while (i < j) {
		finalSequence.push_back(arr[i]);
		finalSequence.push_back(arr[j]);
		i++;
		j--;
	}

	if (arr.size() % 2 != 0) {
		finalSequence.push_back(arr[arr.size() / 2]);
	}
	int sum = 0;
	for (int i = 0; i < arr.size()-1; i++) {
		sum += abs(finalSequence[i] - finalSequence[i + 1]);
	}
	sum += abs(finalSequence[arr.size() - 1] - finalSequence[0]);
	return sum;
}

int main() {
	vector<int> arr = { 1, 2, 4, 8 };
	cout << maxAbsoluteDiff(arr);
	
	
	return 0;
}
//O(1) space
long long int maxSum(int arr[], int n) {
	sort(arr, arr + n);
	long long sum = 0;
	int j = n -1;
	int temp =0;
	for(int i = 0; i < n/2; i++){
	    if (temp != 0){
	        sum += temp - arr[i];
	    }
	    sum += arr[j] - arr[i];
	    temp = arr[j];
	    j--;
	}
	sum += temp - arr[0];
	return sum;
}
