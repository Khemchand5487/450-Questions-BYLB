/*
Title: Find a specific pair in Matrix
Link: https://www.geeksforgeeks.org/find-a-specific-pair-in-matrix/
Complexity: TIme - O(N*M), Space - O(1)
*/

#include <bits/stdc++.h>

using namespace std;

int findMaxValue(vector<vector<int>> matrix, int n, int m) {
    int max_so_far = INT_MIN;
    
    //processing last row
    int currmax = matrix[n-1][m-1];
    for(int i=m-2;i>=0;i--) {
        currmax = max(currmax, matrix[n-1][i]);
        matrix[n-1][i] = currmax;
    }
    
    //processing last column
    currmax = matrix[n-1][m-1];
    for(int i=n-2;i>=0;i--) {
        currmax = max(currmax, matrix[i][m-1]);
        matrix[i][m-1] = currmax;
    }
    
    // processing rest of matrix
    int diff;
    for(int i=n-2;i>=0;i--) {
        for(int j=m-2;j>=0;j--){
            diff = matrix[i+1][j+1] - matrix[i][j];
            max_so_far = max(diff, max_so_far);
            
            matrix[i][j] = max(matrix[i][j], max(matrix[i+1][j], matrix[i][j+1]));
        }
    }
    
    return max_so_far;
    
}

int main()
{
    vector<vector<int>> matrix = {
                      { 1, 2, -1, -4, -20 },
                      { -8, -3, 4, 2, 1 },
                      { 3, 8, 6, 1, 3 },
                      { -4, -1, 1, 7, -6 },
                      { 0, -4, 10, -5, 1 }
                    };
    cout << "Maximum Value is "
         << findMaxValue(matrix, 5, 5);

    return 0;
}
