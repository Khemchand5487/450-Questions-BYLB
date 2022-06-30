/*
Title: Median in a row-wise sorted Matrix 
Link: https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
Complexity: TIme - O(32*R*log(C)), Space - O(1)
*/

int median(vector<vector<int>> &matrix, int r, int c){
    // code here  
    int mn = INT_MAX, mx = INT_MIN;
    for(int i=0;i<r;i++) {
        mn = min(mn, matrix[i][0]);
        mx = max(mx, matrix[i][c-1]);
    }
    
    int req = (r*c+1)/2;
    while(mn < mx) {
        int mid = mn + (mx-mn)/2;
        
        int count = 0;
        for(int i=0;i<r;i++){
            count+=upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        if(count < req) mn = mid+1;
        else mx = mid;
    }
    
    return mn;
}