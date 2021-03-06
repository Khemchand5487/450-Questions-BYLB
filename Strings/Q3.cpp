/*
Title: Print all the duplicates in the input string
Link: https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/
Complexity: TIme - O(N), Space - O(N)
*/


#include <bits/stdc++.h>
using namespace std;
void printDups(string str)
{
    unordered_map<char, int> count;
    for (int i = 0; i < str.length(); i++) {
        count[str[i]]++;
    }
  
    for (auto it : count) {
        if (it.second > 1)
            cout << it.first << ", count = " << it.second
                 << "\n";
    }
}

int main()
{
    string str = "test string";
    printDups(str);
    return 0;
}