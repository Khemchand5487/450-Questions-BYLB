/*
Title: 344. Reverse String
Link: https://leetcode.com/problems/reverse-string/submissions/
Complexity: TIme - O(N), Space - O(1)
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0;i<s.size()/2;i++){
            swap(s[i], s[s.size()-1-i]);
        }
    }
};