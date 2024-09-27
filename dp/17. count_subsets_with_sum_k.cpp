// problem link : https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1?

// Memoization : 
// take care of case like : [0,0,1] , sum = 1 


int mod = 1e9 + 7 ;
int perfectSum(int arr[], int n, int sum)
{
    vector<vector<int>>dp(n, vector<int>(sum+1, -1));
    return solve(n-1, arr, sum, dp);
}

int solve(int ind, int arr[], int sum, vector<vector<int>>&dp){
        
    if (ind == 0) {
        if (sum == 0 && arr[0] == 0) return 2 ;
        if (sum == 0 || sum == arr[0]) return 1 ;
        return 0;
    }
    
    if (dp[ind][sum] != -1) return dp[ind][sum];
    
    int ntake = solve(ind-1, arr, sum, dp) % mod ;
    int take = 0 ;
    if (arr[ind] <= sum)
        take = solve(ind-1, arr, sum -arr[ind], dp) % mod ;
        
    return dp[ind][sum] = (take + ntake) % mod;
}

// tabulation :

int mod = 1e9 + 7 ;
int perfectSum(int arr[], int n, int sum)
{
    vector<vector<int>>dp(n+1, vector<int>(sum+1));
    
    for (int i = 0 ; i <= n ; i++)
        dp[i][0] = 1 ;
        
    for (int i = 1; i <= n ;i ++){
        for (int j = 0 ; j <= sum ; j++){
            int ntake = dp[i-1][j] % mod;
            int take = 0 ;
            if (arr[i-1] <= j)
                take = dp[i-1][j-arr[i-1]] % mod ;
                
            dp[i][j] = (take + ntake) % mod ; 
        }
    }
    return dp[n][sum];
}