#include <bits/stdc++.h> 

static bool cmp(pair<int, int> a, pair<int, int> b){
    return (a.second < b.second);
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int, int> > v;
    int n = start.size();
    for(int i=0; i<n; i++)
        v.push_back(make_pair(start[i], finish[i]));
    sort(v.begin(), v.end(), cmp);
    int count = 0;
    int ansEnd = -1;
    for(int i=0; i<n; i++){
        if(v[i].first > ansEnd - 1){
            count++;
            ansEnd = v[i].second;
        }
    }
    return count;
}