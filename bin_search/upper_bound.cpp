// upper bound : The upper bound in a sorted array is the index of the 
// first value that is greater than a given value.

int upperBound(vector<int> &arr, int x, int n){
	int  l = 0, r = n-1 ;
	while(l <= r){
		int mid = l + (r-l)/2 ;
		if (arr[mid] > x ) r = mid -1 ;
		else l = mid + 1;
	}	

	if (l < n && arr[l] == x) return l+1;
	return l;
}