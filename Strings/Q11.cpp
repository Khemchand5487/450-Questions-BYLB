/*
Title: Permutations of a given string
Link: https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
Complexity: TIme - O(n*n!), Space - O(n)
*/

void permute(string s, int index, set<string>& ans)
{
    if(index == s.length())
    {
        ans.insert(s);
        return;
    }
    for(int i=index ; i<s.length() ; i++)
    {
        swap(s[index], s[i]);
        permute(s, index+1, ans);
        swap(s[index], s[i]);
    }
    
}
vector<string> find_permutation(string S)
{
    // Code here there
    set<string> ans;
    permute(S, 0, ans);
    
    vector<string> res(ans.begin(), ans.end());
    
    return res;
}