// Prob link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
// The idea is to simply track the min price, profit till that point and max profit till then
// TC = O(n)
// SC = O(1)

int maxProfit(vector<int>&nums){
    int n = nums.size();
    int mxprof  = 0 , min_price = INT_MAX;

    for(int i = 0; i < n; i++){
        if (nums[i] < min_price)
            min_price = nums[i];

        else if (mxprof < nums[i] - min_price)
            mxprof = nums[i] - min_price;
    }
    return mxprof;
}