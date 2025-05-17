// idea is to use dp here as we have a choice whether we want to pick or not pick 
// also we need to return the max sum possible, we need some precomputed data in order to store that

// Memoization:

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n, -1);
    return solve(n-1, nums, dp);
}

int solve(int ind, vector<int>&nums, vector<int>&dp){
    if (ind == 0) return nums[0];
    if (ind < 0) return 0;

    if (dp[ind] != -1) return dp[ind];

    int ntake = 0 + solve(ind-1, nums, dp);
    int take = nums[ind] + solve(ind-2, nums, dp);

    return dp[ind] = max(take, ntake);
}

// Tabulation: 

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n,0);

    dp[0] = nums[0];

    for (int i = 1 ; i < n ; i++){
        int ntake = 0 + dp[i-1];
        int take = nums[i] ;
        if (i > 1)
            take += dp[i-2];

        dp[i] = max(take, ntake);
    }
    return dp[n-1];
}

// optimized tabulation:

int rob(vector<int>& nums) {
    int n = nums.size();
    int prev = 0, prev2 = 0 ;

    prev = nums[0];

    for (int i = 1 ; i < n ; i++){
        int ntake = 0 + prev;
        int take = nums[i] ;
        if (i > 1)
            take += prev2;

        int curr = max(take, ntake);
        prev2 = prev ;
        prev = curr ;
        
    }
    return prev;
}