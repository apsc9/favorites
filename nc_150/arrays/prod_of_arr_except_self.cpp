// Brute force : use 2 for loops except when i == j
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int>ans(n);

    for (int i = 0 ; i < n ; i++){
        int product = 1 ;
        for (int j = 0 ; j < n ; j++){
            if (i != j){
                product *= nums[j];
            }
        }
        ans[i] = product;
    }
    return product;
} 

// Use the concept of prefix and suffix product arrays ;
// we will store the prefix multiplication and the corresponding suffix multiplication
// for every element and in the final answer we will just multiply both
// TC = O(n)
// SC = O(n)
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int>ans(n) ;
    vector<int>left(n), right(n);
    
    left[0] = 1;
    for (int i = 1; i < n ; i++){
        left[i] = nums[i-1]*left[i-1];
    }
    right[n-1] = 1;
    for(int i = n-2; i >= 0 ;i--){
        right[i] = nums[i+1] * right[i+1];
    }

    
    for(int i = 0 ; i < n ; i++){
        ans[i] = left[i]* right[i];
    }
    return ans;
}

// Optimized version of above approach:
// Instead of storing it in 2 separate arrays, we can just make use of the 
// final output array in order to store the prefix multiplication and then 
// traverse from the right to get the answer 

// TC = O(n)
// SC = O(1)

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int>ans(n, 1);

    int curr = 1;
    for (int i = 0; i < n ; i++){
        ans[i] = ans[i] * curr ;
        curr = curr * nums[i];
    }

    curr = 1;
    for (int i = n-1; i>= 0; i--){
        ans[i] = ans[i] * curr ;
        curr = curr * nums[i];
    }
    return ans;
}