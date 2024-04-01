// Tabulation with space optimization : the problem is exactly similar to the unique paths 
// problem just one more extra base case is added over here where if if hits an obstacle there is 
// no way to move fwd, and hence returns 0

int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int n = grid.size() , m = grid[0].size();
    vector<int>dp(m,0);

    for (int i = 0 ; i < n ; i++){
        vector<int>temp(m,0);
        for (int j = 0 ; j < m ; j++){
            if (grid[i][j] == 1) temp[j] = 0 ;
            else if (i == 0 && j == 0) temp[j] = 1;
            else {
                temp[j] = dp[j] + ((j > 0) ? temp[j-1] : 0);
            }
        }
        dp = temp;
    }
    return dp[m-1];
}