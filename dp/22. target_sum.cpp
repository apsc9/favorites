// problem can be mapped to count number of subsets with given diff  which makes use of the concept of dp on subsequence
// Approach 1 : Memoization: 
// handle the case where target is negative and the sum of total and given diff is odd 
// also handle the base case properly
// TC = O(n*k) , because of total num of states/subproblems
// SC = O(n*m) + O(n) , 2d Array and recursion stack space 

int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0 ;
    for (auto x : nums){
        sum += x ;
    }
    if ((sum + target) % 2 || (sum + target) < 0) return 0 ; 
    int val = (sum + target) / 2 ;
    int n = nums.size() ;
    vector<vector<int>>dp(n, vector<int>(val+1, -1));

    return solve(n-1, nums, val, dp);
}

int solve(int ind, vector<int>&nums, int sum, vector<vector<int>>&dp){
    if (ind == 0) {
        if (sum == 0 && nums[0] == 0)
            return 2 ;
        if (sum == 0 || sum == nums[0])
            return 1 ;
        return 0 ;
    }

    if (dp[ind][sum] != -1) return dp[ind][sum] ;

    int npick = solve(ind-1, nums, sum, dp);
    int pick = 0 ;
    if (nums[ind] <= sum)
        pick = solve(ind-1, nums, sum - nums[ind], dp);

    return dp[ind][sum] = pick + npick ;
}

// Tabulation : Modification of the above approach 
// TC = O(n*k)
// SC = O(n*k)

int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size() ;
    int total = 0 ;
    for (auto x : nums){
        total += x ;
    }
    if ((total + target) % 2 || (total + target) < 0) return 0 ; 
    int sum = (total + target) / 2 ;
    
    vector<vector<int>>dp(n, vector<int>(sum+1, 0));

    // base cases :
    if (nums[0] == 0) dp[0][0] = 2; // pick and dont pick both valid
    else dp[0][0] = 1 ;

    if (nums[0] != 0 && nums[0] <= sum)
        dp[0][nums[0]] = 1 ; // if equal then pick, else dont pick

    for (int i = 1 ; i < n ; i++){
        for (int j = 0 ; j <= sum ; j++){
            int npick = dp[i-1][j];
            int pick = 0 ;
            if (nums[i] <= j)
                pick = dp[i-1][j - nums[i]];

            dp[i][j] = pick + npick ;
        }
    }   
    return dp[n-1][sum]; 
}

// Tabulation : standard method 
// TC = O(n*k)
// SC = O(n*k)

int findTargetSumWays(vector<int>& nums, int s) {
    int sum = 0 ;
    for(int i = 0; i < nums.size() ; i++){
        sum += nums[i] ;
    }
    return sum+s < 0 || (s + sum) & 1 ? 0 : subsetSum(nums, (s + sum) >> 1); 
}   

int subsetSum(vector<int>& nums, int s) {
    int n = nums.size() ;
    vector<vector<int>> dp(n+1 , vector<int>(s+1 , 0)) ;
    
    for(int i = 0 ; i <= n ; i++)
        dp[i][0] =1 ;
    
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= s ; j++){
            
            if (nums[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]] ;
            else
                dp[i][j] = dp[i-1][j] ;
        }
    }
    return dp[n][s]  ;
}

// optimized tabulation: in tabuln, we only care about prev row , so use 1d arrays , instead of 2d Arrays
// TC = O(n*k)
// SC = O(k)

int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size() ;
    int total = 0 ;
    for (auto x : nums){
        total += x ;
    }
    if ((total + target) % 2 || (total + target) < 0) return 0 ; 
    int sum = (total + target) / 2 ;
    
    vector<int>prev(sum+1, 0);

    // base cases :
    if (nums[0] == 0) prev[0] = 2; // pick and dont pick both valid
    else prev[0] = 1 ;

    if (nums[0] != 0 && nums[0] <= sum)
        prev[nums[0]] = 1 ; // if equal then pick, else dont pick

    for (int i = 1 ; i < n ; i++){
        vector<int>curr(sum+1,0);
        for (int j = 0 ; j <= sum ; j++){
            int npick = prev[j];
            int pick = 0 ;
            if (nums[i] <= j)
                pick = prev[j - nums[i]];

            curr[j] = pick + npick ;
        }
        prev = curr ;
    }   
    return prev[sum]; 
}