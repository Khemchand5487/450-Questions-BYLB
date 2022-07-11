/*
Title: Split the binary string into substrings with equal number of 0s and 1s
Link: https://practice.geeksforgeeks.org/problems/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/1/#
Complexity: TIme - O(n), Space - O(1)
*/

int maxSubStr(string str) {
    int zeros=0, ones=0, substrings=0;
    for(char ch: str) {
        if(ch=='0') zeros++;
        else if(ch=='1') ones++;

        if(zeros==ones) {
            substrings++;
            zeros=0;
            ones=0;
        }
    }
    
    return zeros!=ones? -1: substrings;
}