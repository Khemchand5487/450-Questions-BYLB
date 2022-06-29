// Union of two arrays

int doUnion(int a[], int n, int b[], int m)  {
    unordered_set<int> s;

    int ans=0;
    for(int i=0;i<n;i++) {
        if(s.find(a[i]) == s.end()) {
            ans++;
        }
        s.insert(a[i]);
    }

    for(int i=0;i<m;i++) {
        if(s.find(b[i]) == s.end()) {
            ans++;
        }
        s.insert(b[i]);
    }

    return ans;
}
