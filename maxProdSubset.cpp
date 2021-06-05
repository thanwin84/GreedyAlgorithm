#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
using namespace std;
int maxProduct(vector<int> arr) {
	int product = 1;
	int maxNeg = INT_MIN;
	int countNeg = 0;
	int countZeros = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == 0) {
    //adding 0 will make everything zero
			countZeros++;
			continue;
		}

		else if (arr[i] < 0) {
			countNeg++;
			maxNeg = max(maxNeg, arr[i]);
		}
		product *= arr[i];
	}
	//if all is 0, then prod will be 0
	if (countZeros == arr.size()) {
		return 0;
	}
	else if (countNeg == 1 and countNeg + countZeros == arr.size()) {
		return 0;
	}
   //if we get odd number of negative, then we have to discard max neg
    //so that overall product become max
	else if (countNeg % 2 != 0) {
		product = product / maxNeg;
		return product;
	}
	return product;
}

int main() {
	vector<int> arr = { -1, -1, -2, 4, 3 };
	vector<int> arr2 = { -1, -1,  4, 3 };
	vector<int> arr3 = { 0, 0, 0, -1 };
	cout << maxProduct(arr3) << endl;
	cout <<maxProduct(arr) << endl;
	cout << maxProduct(arr2) << endl;
	
	return 0;
}
