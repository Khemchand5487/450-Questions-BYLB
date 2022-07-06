/*
Title: A Program to check if strings are rotations of each other or not
Link: https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/
Complexity: TIme - O(n1+n2), Space - O(N)
*/

#include <bits/stdc++.h>

using namespace std;

bool areRotations(string s1, string s2) {
    int n=s1.length(), m=s2.length();
    
    if(n!=m) return false;
    
    queue<char> q1;
    for(char ch: s1) q1.push(ch);
    queue<char> q2;
    for(char ch: s2) q2.push(ch);
    
    while(m--) {
        char temp = q2.front();
        q2.pop();
        q2.push(temp);
        if(q1==q2) return true;
    }
    
    return false;
}

int main()
{
    cout<<areRotations("ABAD", "ADAB");

    return 0;
}
