#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
using namespace std;

int maxStock(vector<int> arr, int k) {
    int totalStock = 0;
    int availablePrice = k;
    vector<vector<int>> stockPrice;
    for (int i = 0; i < arr.size(); i++) {
        stockPrice.push_back({ arr[i], i + 1 });
    }
    sort(stockPrice.begin(), stockPrice.end());
    for (int i = 0; i < arr.size(); i++) {
        int price = stockPrice[i][0];
        int stock = stockPrice[i][1];
        if (price * stock <= availablePrice) {
            totalStock += stock;
            availablePrice -= (stock * price);
        }
        else {
            totalStock += (availablePrice/price);
            availablePrice -= price *(availablePrice/price);
        }
    }
    return totalStock;
}
int main() {
    vector<int> price = { 10, 7, 19 };
    cout << maxStock(price, 45);
    
    
	return 0;
}
