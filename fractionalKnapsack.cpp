struct Item {
    int value;
    int weight;
};
struct Pair {
    int value;
    int weight;
    double ratio;
    Pair(int value, int weight, double ratio) {
        this->value = value;
        this->weight = weight;
        this->ratio = ratio;
    }
};
bool comp(Pair p1, Pair p2) {
    return p1.ratio > p2.ratio;
}

class Solution
{
public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<Pair> items;
        double profit = 0;
        for (int i = 0; i < n; i++) {
            double ratio = ((double)arr[i].value) / (double)arr[i].weight;
            items.push_back(Pair(arr[i].value, arr[i].weight, ratio));
        }
        sort(items.begin(), items.end(), comp);
        for (int i = 0; i < n; i++) {
            if (W <= 0) {
                break;
            }
            if (W >= items[i].weight) {
                profit += items[i].value;
                W = W - items[i].weight;
            }
            else {
                profit += items[i].ratio * W;
                W = W - W;

            }
        }
        return profit;
        
    }

};
