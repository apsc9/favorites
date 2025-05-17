// memoization:

int minimumEnergy(vector<int>& height, int n) {
    vector<int>dp(n+1,-1);
    return solve(n-1, height, dp);
}

int solve(int ind, vector<int>&height, vector<int>&dp){
    if(ind == 0) return 0;
    if (dp[ind] != -1) return dp[ind];
    
    int first = solve(ind-1, height, dp) + abs(height[ind] -height[ind-1]);
    int sec = INT_MAX;
    if (ind > 1)
        sec = solve(ind - 2, height, dp) + abs(height[ind] - height[ind-2]);
        
    return dp[ind] = min(first, sec);
        
}

// tabulation :

int minimumEnergy(vector<int>& height, int n) {
    vector<int>dp(n,0);
    dp[0] = 0 ;
    
    for (int i = 1; i < n; i++){
        int first = dp[i-1] + abs(height[i] - height[i-1]);
        int second = INT_MAX;
        if (i > 1)
            second = dp[i-2] + abs(height[i] - height[i-2]);
            
        dp[i] = min(first, second);
    }
    return dp[n-1];
}

// Space optimized tabulation: 
int minimumEnergy(vector<int>& height, int n) {
    int prev= 0, prev2=0, curr = 0 ;
    
    for (int i = 1; i < n; i++){
        int first = prev + abs(height[i] - height[i-1]);
        int second = INT_MAX;
        if (i > 1)
            second = prev2 + abs(height[i] - height[i-2]);
            
        curr = min(first, second);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}