// Approach 1: Idea is to find the index of min elem first in the sorted rotated arr
// then we can apply binary search on both the parts and try to find the elem, 

int search(vector<int>& nums, int target) {
    int index = findMinIndex(nums);
    int n = nums.size();

    int first_half = search(nums, 0, index-1, target);
    int second_half = search(nums, index, n-1, target);

    if (first_half != -1) return first_half;
    else if (second_half != -1) return second_half;
    else return -1;
}

int search(vector<int>&nums, int start, int end, int target){
    while(start <= end){
        int mid = start + (end - start)/2 ;
        if (nums[mid] == target) 
            return mid;
        else if (nums[mid] < target)
            start = mid + 1 ;
        else end = mid - 1;
    }
    return -1 ;
}

int findMinIndex(vector<int>& nums) {
    int n = nums.size(), l = 0, r = n-1 ;
    while(l < r){
        if (nums[l] < nums[r]) return l;
        int mid = l + (r-l)/2 ;
        if (nums[mid] > nums[r])
            l = mid + 1;
        else r = mid;
    }
    return l;
}

// optimal approach : for every element, either the left or the right half is sorted
// we will try to figure out the sorted half first and then try to reduce the search space

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0, r = n-1;

    while (l <= r){
        int mid = l + (r-l)/2;

        if (nums[mid] == target) return mid ;

        if (nums[l] <= nums[mid]) { // left part sorted
            if (nums[l] <= target && target <= nums[mid])
                r = mid - 1;
            else 
                l = mid + 1 ;
        } else { // the right part is sorted
            if (nums[mid] <= target && target <= nums[r])
                l = mid + 1;
            else 
                r = mid - 1;

        }
    }
    return -1 ;
}