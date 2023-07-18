#include <bits/stdc++.h> 

void heapify(vector<int> &arr, int n, int i){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < n && arr[smallest] > arr[left])
        smallest = left;
    if(right < n && arr[smallest] > arr[right])
        smallest = right;
    if(smallest != i){
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}

int deleteElement(vector<int> &arr, int n){
    if(n == 0)
        return -1;

    int ans = arr[0];

    if(n == 1){
        arr.pop_back();
        return ans;
    }
    
    arr[0] = arr[n - 1];
    ans = arr[0];
    arr.pop_back();
    heapify(arr, n, 0);
    
    return ans;
}

void insert(vector<int> &arr, int n, int num){
    arr.push_back(num);
    
    if(n == 1)
        return;
        
    int index = n - 1;
    
    while(index > 0){
        int parentIndex = (index - 1)/2;
        if(parentIndex > index){
            swap(arr[parentIndex], arr[index]);
            index = parentIndex;
        }
        else
            break;
    }
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> arr;
    vector<int> ans;
    for(int i=0; i<n; i++){
        vector<int> query = q[i];
        if(query[0] == 0)
            insert(arr, arr.size(), query[1]);
        else{
            int res = deleteElement(arr, arr.size());
            ans.push_back(res);
        }
    }
    return ans;
}
