#include <bits/stdc++.h>

int allocation(int barrier, vector<int> &A){
    int stud = 1, pages = 0;
    for(int i=0; i<A.size(); i++){
        if(pages + A[i] > barrier){
            stud++;
            pages = A[i];           
        }
        else
            pages += A[i];
    }
    return stud;
}

int Solution::books(vector<int> &A, int B) {
    if(B > A.size())
        return -1;
    int low = *max_element(A.begin(), A.end());
    int high = accumulate(A.begin(), A.end(), 0);
    while(low <= high){
        int mid = (low + high)/2;
        int stud = allocation(mid, A);
        if(stud > B)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
