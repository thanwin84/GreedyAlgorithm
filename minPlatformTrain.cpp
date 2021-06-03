#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
using namespace std;
class Solution{
    public:
        //Function to find the minimum number of platforms required at the
        //railway station such that no train waits.
        int findPlatform(int arr[], int dep[], int n)
        {
            // Your code here
            sort(arr, arr + n);
            sort(dep, dep + n);
            int i = 1;
            int j = 0;
            int needed_platform = 1;
            int max_platform = 1;
            //if there is no incoming train, we dont need to check further
            while (i < n) {
                //we need platform for incoming train
                if (arr[i] <= dep[j]) {
                    needed_platform += 1;
                    i++;
                }
                //if a train departs, then one platform will be empty
                else {
                    needed_platform -= 1;
                    j++;
                }
                //we need to find the maximum of each iteration, that will be the minimum
                //platform needed in a day
                max_platform = max(max_platform, needed_platform);
            }
            return max_platform;
        }
};

int main() {
    int arr[] = {900, 940, 950, 1100, 1500, 1800 };
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
    Solution obj;
    cout << obj.findPlatform(arr, dep, 6);
    
	return 0;
}
