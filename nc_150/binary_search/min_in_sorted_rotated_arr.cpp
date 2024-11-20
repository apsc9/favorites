// the idea is to simply figure out first whether the arr is rotated or not
// if the arr is rotated, we need to find the half where min elem is located
// first check : whether there is actually a rotation or not
// next : when we are sure that there is, we need to check the half where we can get the answer
// we can make use of either the first elem or the last elem to figure it out
// say first elem : if mid >= first , then l = mid + 1  (case : [2,1])
// else r = mid 

// say last elem : if mid > last , so second half 
// else first half

// TC = O(logn)
// SC = O(1)

int findMin(vector<int>& nums) {
    int n = nums.size(), l = 0, r = n-1 ;
    
    while(l < r){
        if (nums[l] < nums[r]) return nums[l];

        int mid = l + (r-l)/2 ;

        // now we are already meeting the condition where first > last
        // so min has to be somewhere in between, we can either compare it with the 
        // start or the end 

        if (nums[mid] > nums[r])
            l = mid + 1;
        else r = mid;

        // if (nums[mid] >= nums[l])
        //     l = mid + 1;
        // else r = mid ;
    }
    return nums[l];
}