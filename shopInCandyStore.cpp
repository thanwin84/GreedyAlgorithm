class Solution
{
public:
    vector<int>  candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        int total = N;
        int minAmount = 0;
        sort(candies, candies + N);
        for (int i = 0; i < N; i++) {
            minAmount += candies[i];
            total -= K + 1;
            if (total <= 0) {
                break;
            }
        }
        total = N;
        int maxAmount = 0;
        for (int i = N - 1; i >= 0; i--) {
            maxAmount += candies[i];
            total -= K + 1;
            if (total <= 0) {
                break;
            }
        }
        return { minAmount, maxAmount };

    }
};
