/*
Title: 74. Search a 2D Matrix
Link: https://leetcode.com/problems/search-a-2d-matrix/
Complexity: TIme - O(log()r+log(c)), Space - O(1)
*/

class Solution {
public:
    bool binarySearch(vector<int> arr, int s, int e, int target) {
        if(s<=e) {
            int mid = s + (e-s)/2;
            if(arr[mid] == target) return true;
            else if(arr[mid]>target) {
                return binarySearch(arr, s, mid-1, target);
            }
            else return binarySearch(arr, mid+1, e, target);
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low= 0, high = matrix.size()-1;
        while(low<=high) {
            int mid = low + (high-low)/2;
            
            if(matrix[mid][0]<=target and matrix[mid][matrix[mid].size()-1] >=target) {
                return binarySearch(matrix[mid], 0, matrix[mid].size(), target);
            }
            else if(matrix[mid][0] > target) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return false;
    }
};