vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int m = A.size();
    int n = B.size();
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=m-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            if(pq.size() == C){
                int sum = A[i] + B[j];
                if(pq.top() < sum){
                    pq.pop();
                    pq.push(sum);
                }
                else break;
            }
            else
                pq.push(A[i] + B[j]);
        }
    }
    vector<int> ans(C,0);
    for(int i=0; i<C; i++){
        ans[C - i - 1] = pq.top();
        pq.pop();
    }
    return ans;  
}
