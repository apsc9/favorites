


int minimumDifference(vector<int>& nums) {
    int n = nums.size();
    int sum = 0 ;
    for (auto x : nums) sum += x ;

    vector<vector<bool>>dp(n, vector<bool>(sum+1, 0));
    for (int i = 0 ; i < n ; i++)
        dp[i][0] = true ;

    //dp[0][nums[0]] = true ;
    for (int i = 1 ; i < n ; i++){
        for (int j = 1 ; j <= sum ; j++){
            bool ntake = dp[i-1][j];
            bool take = false;
            if (nums[i] <= j)
                take = dp[i-1][j-nums[i]];

            dp[i][j] = take | ntake ;
        }
    }


    int mini = 1e9;
    for (int i = 0; i <= sum/2 ; i++){
        if (dp[n-1][i] == true)
            mini = min(mini, abs((sum-i) - i));
    }
    return mini;
}