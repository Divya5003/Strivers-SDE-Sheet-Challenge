pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	long long sn = ((long long)n * ((long long)n + 1))/2;
	long long s2n = ((long long)n * ((long long)n + 1) * (2 * (long long)n + 1))/6;
	long long s = 0, s2 = 0;
	for(int i=0; i<n; i++){
		s += (long long)arr[i];
		s2 += (long long)arr[i] * (long long)arr[i];
	}
	long long val1 = sn - s;
	long long val2 = s2n - s2;
	val2 = val2/val1;
	long long m = (val1 + val2)/2;
	long long r = m - val1;
	return {(int)m, (int)r};
}