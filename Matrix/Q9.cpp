/*
Title: Kth element in Matrix
Link: https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1#
Complexity: TIme - O(k*log(N)), Space - O(N)
*/

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    
    // lambda funstion
    auto cmp = [&](pair<int,int> a,pair<int,int> b){
        return mat[a.first][a.second] > mat[b.first][b.second];
    };
     
    //DECLARING priority_queue AND PUSHING FIRST ROW IN IT
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
    for(int i=0; i<n; i++){
        pq.push({i,0});
    }
     
    //RUNNING LOOP FOR (k-1) TIMES
    for(int i=1; i<k; i++){
        auto p = pq.top();
        pq.pop();
         
        //AFTER POPPING, WE'LL PUSH NEXT ELEMENT OF THE ROW IN THE HEAP
        if(p.second+1 < n) pq.push({p.first,p.second + 1});
    }
    // ON THE k'th ITERATION, pq.top() will be our answer.
    return mat[pq.top().first][pq.top().second];
}

/*
Time complexity: O(x*n*log(n));

where, x = log(abs(mat[0][0] - mat[n-1][n-1]))

Space complexity: O(1)
*/

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  int start = mat[0][0], end = mat[n-1][n-1], mid;
  
  while(start<=end) {
      mid = (start+end)/2;
      int count = 0;
      
      for(int i=0;i<n;i++)
      {
        int l=0, h=n-1, m;
        while(l<=h) {
          m = l + (h-l)/2;
          
          if(mat[i][m] <= mid) l = m+1;
          else h = m-1;
        }
        count+=l;
      }
      
      if(count < k) start = mid+1;
      else end = mid-1;
  }
  
  return start;
}