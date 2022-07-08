/*
Title: Permutations of a given string
Link: https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
Complexity: TIme - O(n*n!), Space - O(n)
*/

void permute(string s , string answer, set<string>& ans)
{
    if(s.length() == 0)
    {
        ans.insert(answer);
        return;
    }
    for(int i=0 ; i<s.length() ; i++)
    {
        char ch = s[i];
        string left_substr = s.substr(0,i);
        string right_substr = s.substr(i+1);
        string rest = left_substr + right_substr;
        permute(rest , answer+ch, ans);
    }
    
}
vector<string> find_permutation(string S)
{
    // Code here there
    set<string> ans;
    permute(S, "", ans);
    
    vector<string> res(ans.begin(), ans.end());
    
    return res;
}