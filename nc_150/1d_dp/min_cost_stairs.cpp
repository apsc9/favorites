// memoization: target is to reach to either last or the second last step, whichever min

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int>dp(n, -1);
    return min(solve(n-1, cost, dp), solve(n-2, cost, dp));
}

int solve(int ind, vector<int>&cost, vector<int>&dp) {
    if (ind < 0) return 0 ;
    if (ind == 0 || ind == 1) return cost[ind];
    if (dp[ind] != -1) return dp[ind];

    return dp[ind] = cost[ind] + min(solve(ind-1, cost, dp), solve(ind-2, cost, dp));
}

// tabulation : 
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int>dp(n, 0);
    dp[0] = cost[0], dp[1] = cost[1];

    for (int i= 2; i < n ; i++){
        dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1], dp[n-2]);
}

// optimized tabulation :
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int prev = cost[0], curr = cost[1];

    for (int i= 2; i < n ; i++){
        int val = cost[i] + min(prev, curr);
        prev = curr;
        curr = val ;
    }
    return min(prev, curr);
}
