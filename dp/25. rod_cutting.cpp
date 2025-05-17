// Problem: https://www.geeksforgeeks.org/problems/rod-cutting0840/1
// the problem can be thought of as : 
// try to pick lengths and sum them up to make N, that way we can just map it 
// to the classical knapsack problem (unbdd)
// index will give us the rod_len and the N will give us 
// the total len of which stick has to be made

int cutRod(vector<int> &price) {
    int n = price.size();
    vector<vector<int>>dp(n, vector<int>(n+1, -1));
    
    return solve(n-1, n, price, dp);
}

int solve(int ind, int N, vector<int>&price, vector<vector<int>>&dp){
    if (ind == 0){
        return N*price[0];
    }
    
    if (dp[ind][N] != -1) return dp[ind][N];
    
    int ntake = 0 + solve(ind-1, N, price, dp);
    int take = INT_MIN;
    int rod_len = ind + 1 ;
    if (rod_len <= N)
        take = price[ind] + solve(ind, N-rod_len, price, dp);
    
    return dp[ind][N] = max(take, ntake);
}

// Tabulation: bottom up approach :

int cutRod(vector<int> &price) {
    int n = price.size();
    vector<vector<int>>dp(n, vector<int>(n+1, 0));
    
    for (int i = 1 ; i <= n ; i++)
        dp[0][i] = i*price[0];
    
    for (int i = 1 ; i < n ; i++){
        for (int j = 0; j <= n ; j++){
            
            int ntake = 0 + dp[i-1][j];
            int take = INT_MIN;
            if (i+1 <= j)
                take = price[i] + dp[i][j-(i+1)];
                
            dp[i][j] = max(take, ntake);
        }
    }
    return dp[n-1][n];
}

// Space optimized tabulation : single array version
// TC = O(n*n)
// SC = O(n)
int cutRod(vector<int> &price) {
    int n = price.size();
    vector<int>prev(n+1,0);
    
    for (int i = 1 ; i <= n ; i++)
        prev[i] = i*price[0];
    
    for (int i = 1 ; i < n ; i++){
        for (int j = 0; j <= n ; j++){
            
            int ntake = 0 + prev[j];
            int take = INT_MIN;
            if (i+1 <= j)
                take = price[i] + prev[j-(i+1)];
                
            prev[j] = max(take, ntake);
        }
    }
    return prev[n];
}