// Problem Link : https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

// the catch here is that we are given first array with size equal to sum of both the arrays
// so if you try to compare from the beginning, it might lead to some reshuffling 
// the array but it is given that the arrays are sorted so we make use of this fact and 
// try to arrange the elements from last to first, that way even there wont be any reshuffling required
// for the first array , moreover this will be done in place 

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m-1 , j = n-1, k = m+n-1 ;

    while(i >= 0 && j >= 0){
        if (nums1[i] >= nums2[j]){
            nums1[k--] = nums1[i--];
        }
        else 
            nums1[k--] = nums2[j--];
    }

    while(j >= 0)
        nums1[k--] = nums2[j--];
}

// TC = O(m+n) ;
// SC = O(1) ;