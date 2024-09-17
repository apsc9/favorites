// Problem link: https://leetcode.com/problems/trapping-rain-water/

// Method 1 : Keep track of the count of max elem on the left and max elem on the right 
// for each element, this way for every entry, we will have corresponding values in the 
// left array and the right array. Once we have the values : we can make use of this 
// res += min(left[i], right[i]) - height[i];

// TC = O(n)
// SC = O(n)

int trap(vector<int>& height) {
    int n = height.size();
    int lmax = 0, rmax = 0 ;
    vector<int>left(n), right(n);

    for (int i = 0 ; i < n ; i++){
        lmax = max(lmax, height[i]);
        left[i] = lmax ;
    }

    for (int i = n-1 ; i >= 0; i--){
        rmax = max(rmax, height[i]);
        right[i] = rmax ;
    }

    int res = 0 ;
    for(int i = 0; i < n ; i++){
        res += min(left[i], right[i]) - height[i];
    }
    return res;
}

// method 2 : use 2 pointer approach  
// The idea is that we just have to keep track of min val between left and right 
// Just keep track of the lmax  and rmax in the corresponding scenarios and update them accordingly
// if in either case lmax or rmax is greater the elem at that index, then add it to the sum 
// TC = O(n)
// SC = O(1)


int trap(vector<int>& height) {
    int n = height.size();
    int l = 0, r = n-1 , res = 0 , lmax = 0, rmax = 0 ;

    // res += min(lmax, rmax) - height[i];

    while(l < r){
        if (height[l] <= height[r]){
            if (lmax < height[l])
                lmax = height[l];

            else 
                res += lmax - height[l];

            l++;
        }

        else {
            if (rmax < height[r])
                rmax = height[r];

            else 
                res += rmax - height[r];

            r--;
        }
    }
    return res;
}