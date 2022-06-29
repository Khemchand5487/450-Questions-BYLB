/*
Title: Kadane's Algorithm
Link: https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
Complexity: Time - O(N); Space - O(1)
*/

long long maxSubarraySum(int arr[], int n){

    long long max_so_far = arr[0], curr_sum = arr[0];

    for(int i=1;i<n;i++) {
        curr_sum = max((long long)arr[i], arr[i]+curr_sum);
        max_so_far = max(curr_sum, max_so_far);
    }

    return max_so_far;
}
