int minimumSumOfAbsoluteDiff(int arr[], int arr2[], int n) {
	sort(arr, arr + n);
	sort(arr2, arr2 + n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += abs(arr[i] - arr2[i]);
	}
	return sum;

}
