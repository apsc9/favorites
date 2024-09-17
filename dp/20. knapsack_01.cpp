// Memoization : 
// TC = O(n*w);
// SC = O(n*w) + O(n);

#include <bits/stdc++.h> 
int knapsack(vector<int> wt, vector<int> val, int n, int mxWt) 
{
	// Write your code here
	vector<vector<int>>dp(n, vector<int>(mxWt+1, -1));
	return solve(n-1, mxWt, wt, val, dp);

}

int solve(int ind, int w, vector<int> wt, vector<int> val, vector<vector<int>>&dp){
	if (ind == 0){
		if (wt[ind] <= w)
			return val[ind];
		return 0;
	}
	
	if (dp[ind][wt] != -1) return dp[ind][w] ;

	int ntake = 0 + solve(ind -1, w, wt, val, dp);
	int take = INT_MIN;
	if (wt[ind] <= w)
		take = val[ind] + solve(ind -1, w-wt[ind], wt, val, dp);
	
	return dp[ind][w] = max(take, ntake);

}

// Tabulation :
//  TC = O(n*w)
// SC = O(n*w);

int knapsack(vector<int> wt, vector<int> val, int n, int mxWt) 
{
	vector<vector<int>>dp(n, vector<int>(mxWt+1, 0));
	for (int w = wt[0] ; w < mxWt; w++){
		dp[0][w] = val[0];
	}

	for (int i = 1 ; i <n ; i++){
		for (int w = 0; w <= mxWt ; w++){
			int ntake = 0 + dp[i-1][w];
			int take = INT_MIN;

			if (wt[i] <= w )
				take = val[i] + dp[i-1][w-wt[i]];
			
			dp[i][w] = max(take, ntake);
		}
	}
	return dp[n-1][mxWt];
}

// Space optimized tabulation:
// TC = same as above
// SC = O(2*w)

int knapsack(vector<int> wt, vector<int> val, int n, int mxWt) 
{
	vector<int>prev(mxWt+1,0), curr(mxWt+1, 0);
	for (int w = wt[0] ; w < mxWt; w++){
		prev[w] = val[0];
	}

	for (int i = 1 ; i <n ; i++){
		for (int w = 0; w <= mxWt ; w++){
			int ntake = 0 + prev[w];
			int take = INT_MIN;

			if (wt[i] <= w )
				take = val[i] + prev[w-wt[i]];
			
			curr[w] = max(take, ntake);
		}
        prev = curr;
	}
	return prev[mxWt];
}

// single row optimized tabulation method : 
// we will need only a single array to store prev if we store from left to right, this 
// will work as we dont need array before a certain index say w, and the previous val (before index w)
// we would have already calculated in the previous iteration
// this method wont work if you go from left to right as it will override the values on the left
// giving the incorrect error
// TC = same as above
// SC = O(W)

int knapsack(vector<int> wt, vector<int> val, int n, int mxWt) 
{
	vector<int>prev(mxWt+1,0);
	for (int w = wt[0] ; w <= mxWt; w++){
		prev[w] = val[0];
	}

	for (int i = 1 ; i <n ; i++){
		for (int w = mxWt; w >= 0 ; w--){
			int ntake = 0 + prev[w];
			int take = INT_MIN;

			if (wt[i] <= w )
				take = val[i] + prev[w-wt[i]];
			
			prev[w] = max(take, ntake);
		}
	}
	return prev[mxWt];
}
