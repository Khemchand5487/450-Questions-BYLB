// Find minimum and maximum element in an array

pair<long long, long long> getMinMax(long long a[], int n) {
    long long mn=a[0], mx=a[0];
    
    for(int i=1;i<n;i++) {
        mn = min(a[i], mn);
        mx = max(a[i], mx);
    }
    
    return make_pair(mn, mx);
    
}
