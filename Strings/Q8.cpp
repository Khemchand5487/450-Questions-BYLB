/*
Title: Longest Palindrome in a String
Link: https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1#
Complexity: TIme - O(N*N), Space - O(1)
*/


string longestPalin (string S) {
    // code here
    int n = S.length();
    if(n<2 || (n==2 and S[0]==S[1])) return S;
    
    int high, low, max_len = 1, start=0;
    
    for(int i=0;i<n;i++) {
        high = i+1;
        low = i-1;
        
        while(high<n and S[high]==S[i]) high++;
        while(low>=0 and S[low]==S[i]) low--;
        while(low>=0 and high<n and S[high]==S[low]) {
            low--;
            high++;
        }
        
        if(max_len < (high-low-1)){
            max_len = (high-low-1);
            start = low+1;
        }
    }
    
    return S.substr(start, max_len);
}


/*
DP Solution
Complexity: Time - O(N*N); Space - O(N*N);
*/

string longestPalin (string S) {
    // code here
    int n = S.length();
    bool dp[n][n];
    
    int start=0, end=0, max_len = INT_MIN;
    
    for(int g=0;g<n;g++) {
        
        for(int i=0, j=g; j<n; i++, j++) {
            if(g==0) dp[i][j] = true;
            else if(g==1) {
                if(S[i]==S[j]) dp[i][j] = true;
                else dp[i][j] = false;
            }
            else {
                if(S[i]==S[j] && dp[i+1][j-1]) dp[i][j] = true;
                else dp[i][j] = false;
            }
            
            if(dp[i][j] and max_len < (g+1)) {
                start = i;
                end = j;
                max_len = g+1;
            }
        }
        
    }
    string res = "";
    if(end==start) res = S[0];
    else{
        for(int i=start; i<end+1;i++) res+=S[i];
    }
    
    return res;
}