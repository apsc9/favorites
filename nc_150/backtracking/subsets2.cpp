// the idea is to include every valid subset for each recursive call, hence this is the reason 

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>tmp;
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        solve(0, nums, tmp, ans);
        return ans;
    }

    void solve(int ind, vector<int>&nums, vector<int>&tmp, vector<vector<int>>&ans){
    
            ans.push_back(tmp);
       
        for(int i = ind; i < nums.size();i++){
            if (i > ind && nums[i] == nums[i-1]) continue;

            tmp.push_back(nums[i]);
            solve(i+1, nums, tmp, ans);
            tmp.pop_back();
        }
    }
};