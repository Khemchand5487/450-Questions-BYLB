/*
Title: 56. Merge Intervals
Link: https://leetcode.com/problems/merge-intervals/submissions/
Complexity: Time - O(N); Space - O(N)
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        stack<vector<int>> st;
        sort(intervals.begin(), intervals.end());
        
        for(auto interval: intervals) {
            if(st.empty() || st.top()[1] < interval[0]) {
                st.push(interval);
            }
            else {
                st.top()[1] = max(st.top()[1], interval[1]);
            }
        }
        
        vector<vector<int>> res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
