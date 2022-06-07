// Kadane's Algorithm 

long long maxSubarraySum(int arr[], int n){

    long long max_so_far = arr[0], curr_sum = arr[0];

    for(int i=1;i<n;i++) {
        curr_sum = max((long long)arr[i], arr[i]+curr_sum);
        max_so_far = max(curr_sum, max_so_far);
    }

    return max_so_far;
}
