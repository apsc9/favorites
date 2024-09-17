// Problem link : https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

// Memoization :
// Time Complexity : O(N*K)
// Space Complexity : O(N*K) + O(N)

#include<bits/stdc++.h>
using namespace std;

bool fn(int ind , int k , vector<int>&arr, vector<vector<int>>&dp){
    if (k == 0) return true ;
    if (ind == 0) return (arr[0] == k);

    if (dp[ind][k] != -1) return dp[ind][k] ;

    bool not_take = fn(ind-1, k, arr,dp);
    bool take = false ;
    if (arr[ind] <= k)
        take = fn(ind-1, k-arr[ind], arr,dp);

    return dp[ind][k] = take || not_take ;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    
    vector<vector<int>>dp(n, vector<int>(k+1, -1));
    return fn(n-1, k , arr, dp);
}

// Tabulation : 

// TC = O(n*k)
// SC = O(n*k)

bool isSubsetSum(vector<int>arr, int k){
    int n = arr.size();
    vector<vector<bool>>dp(n+1, vector<bool>(k + 1, false));

    // dp[ind][target] : whether you can have target value with values upto index ind
    for (int i = 0 ; i <= n ; i++){
        dp[i][0] = true ;
    }

    
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= k ; j++){

            if (arr[i-1] <= j )
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];

            else 
                dp[i][j] = dp[i-1][j] ;
        }
    }
    return dp[n][k];
}

// Space optimized solution : 
// TC = O(n*k)
// SC = O(k)

bool isSubsetSum(vector<int>arr, int k){
    int n = arr.size();
    vector<bool>dp(k+1, false), temp(k+1, false);
    dp[0] = true , temp[0] = true ;;


    
    for (int i = 1 ; i <= n ; i++){
        // vector<bool>temp(k+1, false);
        // temp[0] = true ;
        for (int j = 1 ; j <= k ; j++){

            if (arr[i-1] <= j )
                temp[j] = dp[j-arr[i-1]] || dp[j];

            else 
                temp[j] = dp[j] ;
        }
        dp = temp ;
    }
    return dp[k];
}

// same concept as above :
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool>prev(k+1, false), curr(k+1, false);
    prev[0] = curr[0] = true ;
    prev[arr[0]] = true ;

    for (int i = 1 ; i < n ; i++){
        for (int j = 1 ; j <= k ; j++){
            bool ntake = prev[j];
            bool take = false;
            if (arr[i] <= j)
                take = prev[j-arr[i]]

            curr[j] = take || ntake ;
        }
        prev = curr;
    }
    return prev[k];
}
