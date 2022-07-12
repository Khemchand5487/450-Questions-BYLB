/*
Title: Word Wrap 
Link: https://practice.geeksforgeeks.org/problems/word-wrap1646/1#
Complexity: TIme - O(n*n), Space - O(n)
*/


int solveWordWrap(vector<int>nums, int k) 
{ 
    // Code here
    int n = nums.size();
    int curr_len, cost, dp[n];
    dp[n-1] = 0;
    for(int i=n-2; i>=0;i--) {
        curr_len = -1;
        dp[i] = INT_MAX;
        for(int j=i;j<n;j++) {
            //if current line contains only onw word then +1 is 
            //canceled by -1 else always takes +1 to represent 
            //space between tw words
            curr_len += (nums[j]+1); 
            if(curr_len > k) break;
            
            if(j==n-1) cost = 0;
            else cost = (k-curr_len)*(k-curr_len) + dp[j+1];
            
            dp[i] = min(cost, dp[i]);
        }
    }
    
    return dp[0];
} 



// this solution takes space complexity of O(n*n) and time complexity of O(n*n)
int dp[501][2001];
    
int util(vector<int>& nums, int& k, int index, int remaining) {
    if(index==nums.size()) return 0;
    
    if(dp[index][remaining]!= -1) return dp[index][remaining];
    
    int cost;
    if(remaining < nums[index]) {
        cost = (remaining+1)*(remaining+1) + util(nums, k, index+1, k-nums[index]-1);
    }
    else {
        int choice1 = (remaining+1)*(remaining+1) + util(nums, k, index+1, k-nums[index]-1);
        int choice2 = util(nums, k, index+1, remaining - nums[index] -1);
        cost = min(choice1, choice2);
    }
    dp[index][remaining] = cost;
    return cost;
}

int solveWordWrap(vector<int>nums, int k) 
{ 
    memset(dp, -1, sizeof(dp));
    return util(nums, k, 0, k);
} 