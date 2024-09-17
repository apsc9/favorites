// Memoization : 

// TC = O(n* target)
// SC = O(n*target) + O(target);

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>>dp(n, vector<int>(amount+1, -1));
    int ans = solve(n-1, amount, coins, dp);
    return ans == 1e9 ? -1 : ans ;
    
}

int solve(int ind, int amnt , vector<int>&coins, vector<vector<int>>&dp){
    if (ind == 0){
        if (amnt % coins[0] == 0)
            return amnt/coins[0];
        return 1e9;
    }
    if (dp[ind][amnt] != -1) return dp[ind][amnt];

    int ntake = 0 + solve(ind-1, amnt, coins, dp);
    int take = INT_MAX;
    if (coins[ind] <= amnt)
        take = 1 + solve(ind , amnt - coins[ind], coins, dp);

    return dp[ind][amnt] = min(take, ntake);
}

// Tabulation: 
// tc = O(n* target)
// sc = O(n*target)

int coinChange(vector<int>& coins, int amt) {
    int n = coins.size();
    vector<vector<int>>dp(n, vector<int>(amt+1, 0));
    for(int a  = 0 ; a <= amt ; a++){
        if (a % coins[0] == 0) 
            dp[0][a] = a/coins[0];
        else 
            dp[0][a] = 1e9;
    }

    for (int i = 1 ; i < n ; i++){
        for(int a = 0 ; a <= amt ; a++){
            int ntake = 0 + dp[i-1][a];
            int take = 1e9;
            if (coins[i] <= a) 
                take = 1 + dp[i][a-coins[i]];

            dp[i][a] = min(take, ntake);
        }
    }
    int ans = dp[n-1][amt];
    if (ans == 1e9) return -1 ;
    return ans;
}


// Space optimized tabulation :
// TC = O(n * amnt)
// SC = O(2*amnt)

int coinChange(vector<int>& coins, int amt) {
    int n = coins.size();
    vector<int>prev(amt+1, 0), curr(amt+1, 0);
    for(int a  = 0 ; a <= amt ; a++){
        if (a % coins[0] == 0) 
            prev[a] = a/coins[0];
        else 
            prev[a] = 1e9;
    }

    for (int i = 1 ; i < n ; i++){
        for(int a = 0 ; a <= amt ; a++){
            int ntake = 0 + prev[a];
            int take = 1e9;
            if (coins[i] <= a) 
                take = 1 + curr[a-coins[i]];

            curr[a] = min(take, ntake);
        }
        prev = curr;
    }
    int ans = prev[amt];
    if (ans == 1e9) return -1 ;
    return ans;
}

// Even more optimized method :
// TC = O(n * amnt)
// SC = O(amnt)

int coinChange(vector<int>& coins, int amt) {
    int n = coins.size();
    vector<int>prev(amt+1, 0);
    for(int a  = 0 ; a <= amt ; a++){
        if (a % coins[0] == 0) 
            prev[a] = a/coins[0];
        else 
            prev[a] = 1e9;
    }

    for (int i = 1 ; i < n ; i++){
        for(int a = 0 ; a <= amt ; a++){
            int ntake = 0 + prev[a];
            int take = 1e9;
            if (coins[i] <= a) 
                take = 1 + prev[a-coins[i]];

            prev[a] = min(take, ntake);
        }
    }
    int ans = prev[amt];
    if (ans == 1e9) return -1 ;
    return ans;
}