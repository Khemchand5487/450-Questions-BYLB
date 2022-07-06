/*
Title: 38. Count and Say
Link: https://leetcode.com/problems/count-and-say/submissions/
Complexity: TIme - O(N), Space - O(N)
*/

class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s = countAndSay(n-1);
        
        string res="";
        int i=0;
        while(i<s.length()) {
            int count=1;
            char ch =s[i];
            i++;
            while(s[i]==s[i-1]){
                count++;
                i++;
            }
            res+=to_string(count) + ch;
            
        }
        return res;
    }
};