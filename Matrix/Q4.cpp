/*
Title: Row with max 1s 
Link: https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1#
Complexity: TIme - O(R+C), Space - O(1)
*/

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
    // code here
    int j=m-1, ans=-1;
    for(int i=0;i<n;i++) {
        
        bool flag = false;
        while(j>=0 && arr[i][j] == 1) {
            j--;
            flag = true;
        }
        if(flag) ans = i;
    }
    
    return ans;
}