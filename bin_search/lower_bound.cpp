// 'lower_bound' of a number 'x' is defined as the smallest index 'idx' 
// such that the value 'arr[idx]' is not less than 'x'.

int lowerBound(vector<int> arr, int n, int x) {
	int l = 0, r = n-1 ;

	while(l < r){
		int mid = l + (r-l)/2;
		if (arr[mid] < x){
			l = mid + 1;
		}
		else r = mid ;
	}

	if (r == n-1 && arr[n-1] < x)
		return n;
	return r ;
}