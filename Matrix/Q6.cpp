/*
Title: Max rectangle 
Link: https://practice.geeksforgeeks.org/problems/max-rectangle/1#
Complexity: TIme - O(R*C), Space - O(C)
*/

int maxRec(int row[MAX], int n) {
    int i=0, max_area=0, curr_area, top_ele;
    
    stack<int> s;
    while(i<n) {
        if(s.empty() || row[s.top()] <= row[i]) s.push(i++);
        else {
            top_ele = s.top();
            s.pop();
            
            curr_area = row[top_ele] * (s.empty()? i: i-s.top()-1);
            max_area = max(max_area, curr_area);
        }
    }
    
    while(!s.empty()) {
        top_ele = s.top();
        s.pop();
        
        curr_area = row[top_ele] * (s.empty()? i: i-s.top()-1);
        max_area = max(max_area, curr_area);
    }
    
    return max_area;
}

int maxArea(int M[MAX][MAX], int n, int m) {
    // Your code here
    
    int max_area = maxRec(M[0], m);
    
    for(int i=1;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(M[i][j]) {
                M[i][j]+=M[i-1][j];
            }
        }
        
        max_area = max(max_area, maxRec(M[i], m));
    }
    
    return max_area;
}