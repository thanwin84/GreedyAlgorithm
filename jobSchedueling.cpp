struct Job
{
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
bool comp(Job j1, Job j2) {
    return j1.profit > j2.profit;
}
class Solution
{
public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        sort(arr, arr + n, comp);
        int _max = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (arr[i].dead > _max) {
                _max = arr[i].dead;
            }
        }
        vector<int> deadlines(_max, -1);
        int totalProfit = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            int j = arr[i].dead-1;
            while (j >= 0) {
                if (deadlines[j] == -1) {
                    deadlines[j] = arr[i].id;
                    totalProfit += arr[i].profit;
                    count++;
                    break;
                }
                j--;
            }
        }
        vector<int> result = { count, totalProfit };
        return result;
        
    }
};
