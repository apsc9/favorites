// The problem is slightly different from the others as here we dont have the destination fixed
// we can go to any index in the last row , so for the recurrence relation , normally we go from 
// n to 0, but in this case we will go from 0 to n, so the base case will be when we reach n-1
// we traverse from 0 and keep building on top of it while storing the results for dp

// Memoization :
// TC = O(n*n)
// SC = O(n) + O(n*n)


int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size(), m = triangle[0].size();
    vector<vector<int>>dp(n,vector<int>(n,-1));

    return solve(0,0, triangle, dp);
}

int solve(int i, int j, vector<vector<int>>&triangle, vector<vector<int>>&dp){
    int n = triangle.size();
    if (i == n-1) return triangle[n-1][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = triangle[i][j] + solve(i+1, j , triangle, dp);
    int diag = triangle[i][j] + solve(i+1, j+1, triangle, dp);

    return dp[i][j] = min(down, diag);
}

// Tabulation : usually for tabulation we do opposite of what we do for recursion
// as for recursion we went from 0 to n , so for tabulation we will go from n to 0
// as the no. of cols are variable, we will take 2d vec of n*n

// TC = O(n*n);
// SC = O(n*n) ;

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>>dp(n, vector<int>(n,0));

    for (int j = 0 ; j < n ; j++){
        dp[n-1][j] = triangle[n-1][j];
    }
    int down, diag ;
    for (int i = n-2 ; i >= 0 ; i--){
        for (int j = i ; j >= 0 ; j--){

            down = triangle[i][j] + dp[i+1][j];
            diag = triangle[i][j] + dp[i+1][j+1];

            dp[i][j] = min(down, diag); 
        }
    }
    return dp[0][0];
}

// Space optimized tabulation: we need only the last/upcoming row for the current
// row to be updated and so we only keep the data in 1-d array, that way space can be optimzd
// TC = O(n*n)
// SC = O(n)

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();

    vector<int>dp(n,0);

    for (int j = 0 ; j < n ; j++) dp[j] = triangle[n-1][j];

    int down, diag ;
    for(int i = n-2 ; i >= 0 ; i--){
        vector<int>temp(n,0);
        for (int j = i ; j >= 0 ; j--){
            down = triangle[i][j] + dp[j] ;
            diag = triangle[i][j] + dp[j+1];

            temp[j] = min(down, diag);
        }
        dp = temp;
    }
    return dp[0];
}