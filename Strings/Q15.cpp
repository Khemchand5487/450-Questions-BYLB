/*
Title: Next Permutation
Link: https://practice.geeksforgeeks.org/problems/next-permutation5226/1#
Complexity: TIme - O(n), Space - O(1)
*/

vector<int> nextPermutation(int N, vector<int> arr){
    // code here
    if(N<=1) return arr;
    int i=N-2, j=N-1, flag=0;
    
    while(i>=0 && arr[i] >= arr[i+1]) i--;
    
    if(i>=0) {
        while(arr[i]>=arr[j]) j--;
        swap(arr[i], arr[j]);
    }
    reverse(arr.begin()+i+1, arr.end());
    
    return arr;
    
}