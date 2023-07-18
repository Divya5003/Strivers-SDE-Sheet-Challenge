#include<bits/stdc++.h>

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	priority_queue<int> mx;
	priority_queue<int, vector<int>, greater<int> > mn;
	for(int i=0; i<n; i++){
		mx.push(arr[i]);
		mn.push(arr[i]);
		if(mx.size() > k)
			mx.pop();
		if(mn.size()> k)
			mn.pop();
	}
	return {mx.top(), mn.top()};
}