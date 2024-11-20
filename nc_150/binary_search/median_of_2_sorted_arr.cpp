// Brute force : make an a new array of size m+n, sort the final arr and then provide the 
// median from the sorted array
// TC = O(n1+n2)
// SC = O(n1+n2)


// Second Approach : make use of two pointers and try to find the middle point 
// TC = O(m+n)
// SC = O(1)
// we are given 2 sorted arrays and we could have made a better use of this fact, so we need to 
// optimize it further in the next approach 

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int s1 = nums1.size(), s2 = nums2.size();

    int n1 = 0, n2 = 0, i = 0, j = 0;

    for(int cnt = 0 ; cnt <= (s1+s2)/2 ; cnt++){
        n2 = n1 ;

        if(i < s1 && j < s2){
            if (nums1[i] <= nums2[j]){
                n1 = nums1[i++];
            }
            else {
                n1 = nums2[j++];
            }
        } else if (i < s1) {
            n1 = nums1[i++];
        } else 
            n1 = nums2[j++];
    }

    if ((s1+s2) % 2) {
        return double(n1);
    }

    return double ((n1+n2)/2.0);
}

// Approach 3 : Use Binary Search
// as the 2 arrays are sorted, we can make use of this to find the median of the 2 arrays
// the idea : find two intervals inside each of those arrays from their respective halves such that
// they together imaginarily form the first half of the entire sorted array 
// now when we have 2 halves inside each of them , and we try to find the median, then we need to be 
// looking towards the endpoints for both of the extreme ends , like right of the left half 
// and left of the right half
// overall idea is to find intervals which are close to each other (almost overlap)
// TC = O(log(min(m,n)))
// SC = O(1)

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int s1 = nums1.size(), s2 = nums2.size();
    if (s1 > s2)
        return findMedianSortedArrays(nums2, nums1);

    int n = s1 + s2 ;
    int left = (s1 + s2 + 1)/2; // ideal half should be of this len
    int low = 0, hi = s1 ;

    while(low <= hi) {
        int mid1 = (low + hi)/2;
        int mid2 = left -mid1 ;

        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < s1)
            r1 = nums1[mid1];
        if (mid2 < s2)
            r2 = nums2[mid2];
        if (mid1 - 1 >= 0)
            l1 = nums1[mid1-1];
        if (mid2 - 1 >= 0)
            l2 = nums2[mid2-1];

        if (l1 <= r2 && l2 <= r1){
            if (n%2 == 1){
                return max(l1,l2);
            }
                
            else {
                return double((max(l1,l2)+ min(r1,r2)))/2;
            }
                
        } else if (l1 > r2){
            hi = mid1 - 1 ;
        } else 
            low = mid1 + 1;
    }
    return 0;
}