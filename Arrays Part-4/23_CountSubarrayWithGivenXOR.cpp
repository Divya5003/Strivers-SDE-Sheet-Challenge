#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    int xr = 0;
    map<int, int> mp;
    mp[xr] = 1;
    int count = 0;
    for(int i=0; i<arr.size(); i++){
        xr ^= arr[i];
        int k = xr^x;
        count += mp[k];
        mp[xr]++;
    }
    return count;
}