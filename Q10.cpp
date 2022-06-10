// Minimum number of jumps

int minJumps(int arr[], int n){
    if(n<=1) return 0;
    if(arr[0]==0) return -1;

    // dp solution in O(N*N)
    // int dp[n];
    // dp[n-1] = 0;
    // for(int i=n-2;i>=0;i--) {

    //     int curr_min = INT_MAX;
    //     int steps = arr[i];
    //     for(int j=1; j<=steps && i+j < n; j++) {
    //         if(dp[i+j] != -1 && dp[i+j] < curr_min) {
    //             curr_min = dp[i+j];
    //         }
    //     }

    //     if(curr_min == INT_MAX) {
    //         dp[i] = -1;
    //     }
    //     else {
    //         dp[i] = curr_min+1;
    //     }
    // }

    // return dp[0];
    int steps = arr[0], maxReach = arr[0], jumps = 1;

    for(int i=1;i<n-1;i++) {
        maxReach = max(i+arr[i], maxReach);
        steps--;

        if (i>= maxReach) return -1;
        if(steps==0) {
            jumps++;
            steps = maxReach - i;
        }
    }
    return jumps;
}
