#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
#define n 2
#define m 5
using namespace std;
int maxStop(int arr[][3]) {
    vector<pair<int, int>> TrainStopping[n+1];
    for (int i = 0; i < m; i++) {
        TrainStopping[arr[i][2]].push_back(make_pair(arr[i][1], arr[i][0]));
    }
    //sort time according to each platform
    for (int i = 0; i < n; i++) {
        sort(TrainStopping[i].begin(), TrainStopping[i].end());

    }
    int count = 0;
    int x = 0;
    for (int i = 0; i <= n; i++) {
        //No 0 platform won't have any train
        if (TrainStopping[i].size() == 0) continue;
        count++;
        int x = 0;
        //using activity selection
        for (int j = 1; j < TrainStopping[i].size(); j++) {
            if (TrainStopping[i][j].second > TrainStopping[i][x].first) {
                count++;
                x = j;
            }
        }
    }
    return count;
}
int main() {
    int arr[m][3] = { 1000, 1030, 1,
                      1010, 1020, 1,
                      1025, 1040, 1,
                      1130, 1145, 2,
                      1130, 1140, 2 };
    cout << "Maximum Stopped Trains = "
        << maxStop(arr);
    
	return 0;
}
