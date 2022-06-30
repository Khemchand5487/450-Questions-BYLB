/*
Title: Sorted matrix 
Link: https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1
Complexity: TIme - O(N*Nlog(N)), Space - O(N*N)
*/

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
    // code here
    vector<int> res(0, N*N);
    int k=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) res.push_back(Mat[i][j]);
    }
    sort(res.begin(), res.end());
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            Mat[i][j] = res[k++];
        }
    }
    return Mat;
}