/*
Title: Merge Without Extra Space
link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1
Complexity: Time - O((n+m)log(n+m)); Space - O(1)
*/

void merge(int arr1[], int arr2[], int n, int m) {
    int gap = ceil((float)(n+m)/2);
    while(gap) {
        int i=0, j=gap;
        while(j<m+n) {
            if(j<n && arr1[i] > arr1[j]) swap(arr1[i], arr1[j]);
            else if(i<n && j>=n && arr1[i] > arr2[(j-n)]) {
                swap(arr1[i], arr2[(j-n)]);
                i++, j++;
            } 
            else if(i>=n && j>=n && arr2[i-n] > arr2[j-n]){
                swap(arr2[i-n], arr2[j-n]);
                i++, j++;
            }
            else i++, j++;
        }
        if(gap==ceil((float)gap/2)) break;
        gap = ceil((float)gap/2);
    }
}
