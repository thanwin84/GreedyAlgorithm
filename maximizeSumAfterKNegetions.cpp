lass Solution{
    public:
    long long int maximizeSum(long long int arr[], int n, int k)
    {
        // Your code goes here
        sort(arr, arr + n);
        for(int i = 0; i < n; i++){
            if(arr[i] < 0 and k > 0){
                arr[i] = -arr[i];
                k--;
            }
            if(k == 0){
                break;
            }
        }
        long long sum = 0;
        long long minElement = INT_MAX;
        for(int i = 0; i < n; i++){
            sum+= arr[i];
            if (minElement > arr[i]){
                minElement = arr[i];
            }
        }
        if(k % 2 != 0)sum -= 2 * minElement;
        return sum;
    }
};
