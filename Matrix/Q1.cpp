/*
Title: Spirally traversing a matrix 
Link: https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1#
Complexity: TIme - O(R*C), Space - O(R*C)(to strore the result)
*/

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
{
    // code here 
    vector<int> res;

    int row = 0, col=0;
    while(row<r and col<c){
        for(int i=col;i<c;i++) {
            res.push_back(matrix[row][i]);            
        }
        row++;
        for(int i=row;i<r;i++) {
            res.push_back(matrix[i][c-1]);
        }
        c--;
        if(row < r){
            for(int i=c-1;i>=col;i--) {
                res.push_back(matrix[r-1][i]);
            }
            r--;
        }
        
        if(col<c){
            for(int i=r-1;i>=row;i--) {
                res.push_back(matrix[i][col]);
            }
            col++;
            
        }
    }
    return res;
}