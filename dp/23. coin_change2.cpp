// memoization : 
// TC = O(n* target)
// SC = O(n* target) + O(target)

int change(int amount, vector<int>& coins) {
    int n = coins.size();

    vector<vector<int>>dp(n, vector<int>(amount+1, -1));

    return solve(n-1, coins, amount, dp);
}

int solve(int ind, vector<int>&coins, int amount, vector<vector<int>>&dp){
    if (ind == 0){
        return (amount % coins[0] == 0) ;
            
    }
    if (dp[ind][amount] != -1) return dp[ind][amount];
    int ntake = solve(ind-1, coins, amount, dp);
    int take = 0 ;
    if (coins[ind] <= amount)
        take = solve(ind, coins, amount-coins[ind], dp);

    return dp[ind][amount] = take + ntake;
}

// Tabulation : 2d approach 

int change(int amount, vector<int>& coins) {
    int n = coins.size();

    vector<vector<unsigned>>dp(n, vector<unsigned>(amount+1, 0));

    for(int a = 0 ; a <= amount ; a++){
        if (a % coins[0] == 0)
            dp[0][a] = 1;
    }

    for (int i = 1 ; i < n ; i++){
        for (int j = 0 ; j <= amount; j++){

            unsigned  ntake = dp[i-1][j];
            unsigned take = 0 ;
            if (coins[i] <= j){
                take = dp[i][j-coins[i]];
            }
                
            // if (take+ntake > INT_MAX) return 0;
            dp[i][j] = take + ntake;
        }
    }

    return dp[n-1][amount];

}

// Tab: 1d optimized 
int change(int amount, vector<int>& coins) {
    int n = coins.size();

    vector<vector<unsigned>>dp(n, vector<unsigned>(amount+1, 0));
    vector<unsigned>prev(amount+1, 0), curr(amount+1,0);

    for(int a = 0 ; a <= amount ; a++){
        if (a % coins[0] == 0)
            prev[a] = 1;
    }

    for (int i = 1 ; i < n ; i++){
        for (int j = 0 ; j <= amount; j++){

            unsigned ntake = prev[j];
            unsigned take = 0 ;
            if (coins[i] <= j){
                take = curr[j-coins[i]];
            }
                
            curr[j] = take + ntake;
        }
        prev = curr ;
    }

    return prev[amount];

}

// Tabulation : std method (You can optimize it for 1d array as well like we did above)
int change(int amount, vector<int>& coins) {
    int n = coins.size();

    vector<vector<unsigned>>dp(n+1, vector<unsigned>(amount+1, 0));

    for (int i = 0; i <= n ; i++)
        dp[i][0] = 1 ; 

    for (int i = 1; i <= n ; i++){
        for (int j = 1 ; j <= amount ; j++){

            if (coins[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][amount];
    
}