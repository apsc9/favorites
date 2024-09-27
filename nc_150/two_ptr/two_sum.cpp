// Idea : just basic 2 ptr approach 

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int>ans;
    int n = nums.size();

    int l = 0, r = n-1 ;

    while(l < r){
        if (nums[l] + nums[r] < target)
            l++;
        else if (nums[l] + nums[r] > target)
            r--;
        else {
            ans.push_back(l+1);
            ans.push_back(r+1);
            return ans ;
        }
    }
    return ans;
}