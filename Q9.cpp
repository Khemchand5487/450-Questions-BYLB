// Minimize the Heights II 

int getMinDiff(int arr[], int n, int k) {
    sort(arr, arr+n);

    int ans = arr[n-1] - arr[0];

    int mx=arr[n-1]-k, mn = arr[0]+k;
    for(int i=0;i<n-1;i++) {
        if(arr[i+1]-k < 0) continue;

        mx = max(arr[n-1]-k, arr[i]+k);
        mn = min(arr[0]+k, arr[i+1]-k);

        ans = min(ans, mx-mn);
    }
    return ans;
}
