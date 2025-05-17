// memoization:

int minimizeCost(int k, vector<int>& arr) {
    int n = arr.size();
    
    vector<int>dp(n, 0);
    return solve(n-1, k, arr, dp);
}

int solve(int ind, int k , vector<int>&arr, vector<int>&dp){
    if (ind == 0) return 0;
    if (dp[ind] != -1) return dp[ind];
    
    int minsteps = INT_MAX;
    for (int i = 1; i <= k; i++){
        int jump = INT_MAX;
        if (ind >= i)
            jump = solve(ind-i, k , arr, dp) + abs(arr[ind] - arr[ind-i]);
        minsteps = min(minsteps, jump);
    }
    
    return dp[ind]= minsteps;
}

// tabulation: 

int minimizeCost(int k, vector<int>& arr) {
    int n = arr.size();
    
    vector<int>dp(n, 0);
    dp[0] = 0 ;
    
    
    for (int i = 1; i < n ; i++){
        int minsteps = INT_MAX;
        for (int j=1; j <= k ; j++){
            if (i>= j){
                int jump = dp[i-j] + abs(arr[i] - arr[i-j]);
                minsteps = min(minsteps, jump);
            }
        }
        dp[i] = minsteps;
    }
    return dp[n-1];
}
