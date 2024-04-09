// Greedy approach wont work here due to non-unoformity of the given values , so we try to see 
// a recurrence relation and later on we were able to find the overlapping subproblems with the
// further iterations

// Idea : we dont have a fixed starting and an ending point so we try to find the max path 
// for all the entries in the last row and take what is max of that 
// individually we apply a function for each of those coordinates in the last row
// and try to find the sum with the max value

// I. Memoization : top down approach 
// TC = O(m*n)
// SC = O(n*m) + O(n) for recursion stack space

int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
     int m = matrix[0].size() ;
    if (j < 0 || j >= m ) return -1e8 ;
    if (i == 0) return matrix[0][j];
    if (dp[i][j] != -1 ) return dp[i][j];

    int st = matrix[i][j] + solve(i-1, j, matrix, dp);
    int ld = matrix[i][j] + solve(i-1, j-1, matrix, dp);
    int rd = matrix[i][j] + solve(i-1, j+1, matrix, dp);
    
    return dp[i][j] = max(st, max(ld, rd));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size() ;
    vector<vector<int>>dp(n, vector<int>(m,-1));

    int maxi = -1e8 ;
    for (int j = 0 ; j < m ; j++){
        maxi = max(maxi, solve(n-1, j, matrix, dp));
    }
    return maxi ;
}

// II. Tabulation : bottom up approach 
// Just take care that a path is not considered anymore by assigning to it -ve big val
// that way you are making sure that the path is not taken anymore
// TC = O(n*m)
// SC = O(n*m)

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(),  m = matrix[0].size();
    vector<vector<int>>dp(n, vector<int>(m, 0));
    
    for (int j = 0 ; j < m ; j++){
        dp[0][j] = matrix[0][j];
    }
    for (int i = 1 ; i < n ; i++){
         for(int j = 0 ; j < m ; j++){
             int up = matrix[i][j] + dp[i-1][j];
             int ld = matrix[i][j] ;
             ld += (j-1 >= 0) ? dp[i-1][j-1] : -1e9;
             int rd = matrix[i][j];
            rd +=  (j+1 < m) ? dp[i-1][j+1] : -1e9 ;

            dp[i][j] = max(up, max(ld, rd));
         }
    }

    int mx = dp[n-1][0];
    for (int j = 1 ; j < m ; j++){
        mx = max(mx, dp[n-1][j]);
    }
    return mx ;
}

// III. Tabulation with space optimization : 
// here we realize that actually we need results for only prev array so instead of storing 
// results for all the values, we can simply store the one for the prev row and make use of that

// TC = O(n*m)
// SC = O(m)

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(),  m = matrix[0].size();
    
    vector<int>dp(m,0);
    for (int j = 0 ; j < m ; j++){
        dp[j] = matrix[0][j] ;
    }

    for (int i = 1; i < n ; i++){
        vector<int>temp(m,0);
        for (int j = 0 ; j < m ; j++){
            int up = matrix[i][j] + dp[j];
            int ld = matrix[i][j];
            ld += (j-1 >= 0) ? dp[j-1] : -1e9 ;
            int rd = matrix[i][j];
            rd += (j+1 < m) ? dp[j+1] : -1e9;

            temp[j] = max(up, max(ld, rd));
        }
        dp = temp ;
    }

    int mx = dp[0];
    for (int j = 1 ; j < m ; j++){
        mx = max(mx, dp[j]);
    }

    return mx;
}