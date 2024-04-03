// greedy wont be applicable here as choosing greedily initially might cost us dearly in the later run
// we simply have to explore all the paths in order to find the minimal path and that is where 
// the recursion comes into play, to optimize this recurrence relation we will use memoization:

// I. Memoization : 
// TC = O(n*m)
// SC = O(n*m) + O(n-1 + m-1) (path length)

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>>dp(m, vector<int>(n,-1));

    return solve(m-1, n-1, grid, dp);
}

int solve(int i, int j , vector<vector<int>>& grid, vector<vector<int>>& dp){
    if (i == 0 && j == 0) return grid[i][j];
    if (i < 0 || j < 0) return 1e9;

    if (dp[i][j] != -1) return dp[i][j];

    int up =  solve(i-1, j, grid, dp) + grid[i][j];
    int left = solve(i, j-1, grid, dp) + grid[i][j];
    return dp[i][j] = min(up, left);
}

// II. Tabulation :
// TC = O(n*m);
// SC = O(n*m);

int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>>dp(n, vector<int>(m,0));

    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            if (i == 0 && j == 0)
                dp[i][j] = grid[0][0];
            else {
                int up = ((i > 0) ? dp[i-1][j] : 1e9) + grid[i][j];
                int left = ((j > 0) ? dp[i][j-1] : 1e9) + grid[i][j];
                dp[i][j] = min(left, up);
            }
        }
    }
    return dp[n-1][m-1];
}

// III. Space optimization for tabulation method : as only prev row results were needed
// so we adjust the code accordingly 
// TC = O(n*m)
// SC = O(m)

int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<int>dp(m,0);

    for (int i = 0 ; i < n ; i++){
        vector<int>temp(m,0);
        for (int j = 0 ; j < m ; j++){
            if (i == 0 && j == 0)
                temp[j] = grid[i][j];
            else {
                int up = ((i > 0) ? dp[j]+ grid[i][j] : 1e9);
                int left = ((j > 0) ? temp[j-1] + grid[i][j] : 1e9);

                temp[j] = min(up, left);
            }
        }
        dp = temp;
    }
    return dp[m-1];
}