// memoization :

int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
    // code here
    int n = val.size() ;
    vector<vector<int>>dp(n, vector<int>(capacity+1, -1));
    return solve(n-1, val, wt, capacity, dp);
}

int solve(int ind, vector<int>& val, vector<int>& wt, int W, vector<vector<int>>&dp){
    if (ind == 0){
        return ((int)(W/wt[0])) * val[0];
    }
    if (dp[ind][W] != -1) return dp[ind][W];
    
    int ntake = 0 + solve(ind-1, val, wt, W, dp);
    int take = 0;
    if (wt[ind] <= W)
        take = val[ind] + solve(ind, val, wt, W-wt[ind], dp);
        
    return dp[ind][W] = max(take, ntake);
}

// Tabulation: 
int knapSack(vector<int>& val, vector<int>& wt, int W) {
    // code here
    int n = wt.size();
    vector<vector<int>>dp(n, vector<int>(W+1, 0));
    
    for (int w= 0; w <= W ; w++){
        dp[0][w] = (w/wt[0]) * val[0];
    }
    
    for (int i = 1; i < n ; i++){
        for (int j = 0 ;j <= W ; j++){
            int ntake = 0 + dp[i-1][j];
            int take = 0 ;
            if (wt[i] <= j)
                take = val[i] + dp[i][j-wt[i]];
                
            dp[i][j] = max(take, ntake);
        }
    }
    return dp[n-1][W];
}

// space optimized tabulation: 2 arrays

int knapSack(vector<int>& val, vector<int>& wt, int W) {
    // code here
    int n = wt.size();
    
    vector<int>prev(W+1,0), curr(W+1,0);
    for (int w= 0; w <= W ; w++){
        prev[w] = (w/wt[0]) * val[0];
    }
    
    for (int i = 1; i < n ; i++){
        for (int j = 0 ;j <= W ; j++){
            int ntake = 0 + prev[j];
            int take = 0 ;
            if (wt[i] <= j)
                take = val[i] + curr[j-wt[i]];
                
            curr[j] = max(take, ntake);
        }
        prev = curr ;
    }
    return prev[W];
}

// tabulation: space optimized : single array version

int knapSack(vector<int>& val, vector<int>& wt, int W) {
    // code here
    int n = wt.size();
    
    vector<int>prev(W+1,0);
    for (int w= 0; w <= W ; w++){
        prev[w] = (w/wt[0]) * val[0];
    }
    
    for (int i = 1; i < n ; i++){
        for (int j = 0 ;j <= W ; j++){
            int ntake = 0 + prev[j];
            int take = 0 ;
            if (wt[i] <= j)
                take = val[i] + prev[j-wt[i]];
                
            prev[j] = max(take, ntake);
        }
    }
    return prev[W];
}