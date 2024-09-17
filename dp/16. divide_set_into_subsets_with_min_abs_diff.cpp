// wont work in case of neg values , KS extension

int minimumDifference(vector<int>& nums) {
    int n = nums.size();
    int sum = 0 ;
    for (int i = 0 ; i < n ; i++)
        sum += nums[i];
    
    vector<bool>prev(sum+1, false);
    prev[0] = true ;
    
    for (int i = 1 ; i < n ; i++){
        for (int j = sum ; j >= 0 ; j--){
            bool ntake = prev[j];
            bool take = false;
            if (nums[i] <= j)
                take = prev[j-nums[i]];

            prev[j] = take | ntake ;
        }
    }


    int mini = 1e9;
    for (int i = 0; i <= sum/2 ; i++){
        if (prev[i] == true)
            mini = min(mini, abs((sum-i) - i));
    }
    return mini;
}