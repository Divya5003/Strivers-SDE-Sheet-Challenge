bool isPossible(vector<int> &stalls, int k, int mid, int n) {
    int cowCount = 1;
    int lastPos = stalls[0];
    for(int i=0; i<n; i++ ){
        if(stalls[i] - lastPos >= mid){
            cowCount++;
            if(cowCount == k)
                return true;
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k){
    sort(stalls.begin(), stalls.end());
    int low = 0;
    int n = stalls.size();
    int high = stalls[n - 1];
    int ans = -1;
    while(low <= high){
        int mid = (low + high) >> 1;
        if(isPossible(stalls, k, mid, n)){
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}