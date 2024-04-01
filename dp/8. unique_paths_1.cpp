// the idea here is to get the max number of ways possible, for that we need to explore all the 
// possible ways and so recursion comes into play here 
// while recursing, we can see overlapping subproblems and hence we can optimize it further using
// memoization , which can be followed by tabulation and then space optimized tabulation
// so we make use of dp to solve this problem 

// memoization 
// TC = O(m*n)
// SC = O(n-1 + m-1) +  O(m*n) 
//       recursion     2d array

int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m, vector<int>(n,-1));

    return solve(m-1, n-1, dp);
}

int solve(int i,int j, vector<vector<int>>&dp){
    if (i == 0 && j == 0) return 1 ;
    if (i < 0 || j < 0) return 0 ;
    if (dp[i][j] != -1) return dp[i][j];

    int left = solve(i-1, j, dp);
    int up = solve(i, j-1,dp);
    return dp[i][j] = left + up ;
}

// tabulation : to optimize the space used in recursion stack we use this approach
// TC = O(m*n)
// SC = O(m*n)

int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m, vector<int>(n,0));

    int left, up ;
    for(int i = 0 ; i < m ; i++){
        for (int j = 0 ;j < n ; j++){
            if (i == 0 && j == 0)
                dp[i][j] = 1 ;
            else {
                left = (i >= 1) ? dp[i-1][j] : 0 ;
                up = (j >= 1) ? dp[i][j-1] : 0 ;

                dp[i][j] = left + up ;
            }
        }
    }
    return dp[m-1][n-1];
}

// Space optimized tabulation (kind of): to optimize the space further we will make use of a 
// 1-d dp array as we realize that ultimately we need just prev row in order to get the data from up
// TC = O(m*n)
// SC = O(n)

int uniquePaths(int m, int n) {
    vector<int>dp(n,0);

    for(int i = 0 ; i < m ; i++){
        vector<int>temp(n);
        for (int j = 0 ;j < n ; j++){
            if (i == 0 && j == 0)
                temp[j] = 1 ;
            
            else {
                temp[j] = dp[j] + ((j >= 1) ? temp[j-1] : 0) ;
                        // up.      left
            }
        }
        dp = temp ;
    }
    return dp[n-1];
}