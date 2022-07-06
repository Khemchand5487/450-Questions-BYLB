/*
Title: Palindrome String
Link: https://practice.geeksforgeeks.org/problems/palindrome-string0817/1
Complexity: TIme - O(N), Space - O(1)
*/

class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    int n = S.size()-1;
	    for(int i=0;i<n;i++)
	    {
	        if(S[i]!= S[n]) return 0;
	        n--;
	    }
	    return 1;
	}

};