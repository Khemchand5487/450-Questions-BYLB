/*
Title: Rotate a matrix by 90 degree in clockwise direction without using any extra space
Link: https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/
Complexity: TIme - O(N*M), Space - O(1)
*/

#include <bits/stdc++.h>

using namespace std;

void rotate90clockwise(vector<vector<int>>& matrix, int n) {
    
    int temp;
    for(int i=0;i<n/2;i++) {
        for(int j=i;j<n-1-i;j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[n-j-1][i];
            matrix[n-j-1][i] = matrix[n-1-i][n-1-j];
            matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
            matrix[j][n-1-i] = temp;
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{ 1, 2, 3, 4 },
                                  { 5, 6, 7, 8 },
                                  { 9, 10, 11, 12 },
                                  { 13, 14, 15, 16 } };
    rotate90clockwise(matrix, 4);
    for(auto i: matrix) {
        for(int j: i) cout<<j<<" ";
        cout<<endl;
    }

    return 0;
}
