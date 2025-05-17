// idea is to simply use the logic used in house robber 1 and apply it on 2 different arrays 
// one includes the first element and the other includes the last element
// this way we can handle the cases separately
// return the mx of the two values

int rob(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return nums[0];
    vector<int>temp1, temp2;

    for (int i = 0; i < n ; i++){
        if (i != 0) temp1.push_back(nums[i]);
        if (i != n-1) temp2.push_back(nums[i]);
    }

    return max(robbery(temp1), robbery(temp2));
}

int robbery(vector<int>& nums) {
    int n = nums.size();
    int prev = 0, prev2 = 0 ;

    prev = nums[0];

    for (int i = 1 ; i < n ; i++){
        int ntake = 0 + prev;
        int take = nums[i] ;
        if (i > 1)
            take += prev2;

        int curr = max(take, ntake);
        prev2 = prev ;
        prev = curr ;
        
    }
    return prev;
}