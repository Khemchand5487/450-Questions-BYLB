/*
Title: Program to Check if a string is a valid shuffle of two distinct strings
Link: https://www.programiz.com/java-programming/examples/check-valid-shuffle-of-strings
Complexity: TIme - O(N*log(N)), Space - O(1)
*/

#include <bits/stdc++.h>

using namespace std;

bool isShuffled(string s1, string s2, string shuffle) {
    if((s1.length() + s2.length()) != shuffle.length()) return false;
    
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    sort(shuffle.begin(), shuffle.end());
    
    int i=0, j=0, k=0;
    while(k<shuffle.length()) {
        if(i<s1.length() && s1[i]==shuffle[k]) i++;
        else if(j<s2.length() && s2[j]==shuffle[k]) j++;
        else return false;
        
        k++;
    }
    
    if(i<s1.length() || j<s2.length()) return false;
    
    return true;
    
}

int main()
{
    string first = "XY";
    string second = "12";
    vector<string> results = {"1XY2", "Y1X2", "Y21XX"};

    // call the method to check if result string is
    // shuffle of the string first and second
    for (string result : results) {
      if (isShuffled(first, second, result)) {
        cout<<result<<" is a valid shuffle of "<<first<<" and "<<second<<endl;
      }
      else {
        cout<<result<<" is not a valid shuffle of "<<first<<" and "<<second<<endl;
      }
    }

    return 0;
}
