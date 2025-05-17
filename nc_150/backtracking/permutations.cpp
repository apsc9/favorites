// Idea is to make use of map in order to track which elem has been taken

// TC = O(n! * n)
// SC = O(n) + O(n)

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;

        vector<vector<int>>ans ;
        vector<int>temp ;

        solve(nums, mp, temp, ans);
        return ans ;
    }

    void solve(vector<int>&nums , unordered_map<int, int>&mp, vector<int>&tmp, vector<vector<int>>&ans){
        if (tmp.size() == nums.size()){
            ans.push_back(tmp);
            return;
        }

        for (int i = 0 ; i < nums.size() ; i++){
            if (!mp[nums[i]]){
                tmp.push_back(nums[i]);
                mp[nums[i]]++;
                solve(nums, mp, tmp, ans);
                mp[nums[i]]--;
                tmp.pop_back();
            }
        }
    }
};

// Optimized approach : use swapping in place, this will save extra space for map and tmp array
// TC : O(n! * n)
// SC = O(n) , recursion stack space only

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        

        vector<vector<int>>ans ;
        vector<int>temp ;

        solve(0, nums, ans);
        return ans ;
    }

    void solve(int ind, vector<int>&nums, vector<vector<int>>&ans){
        if (ind == nums.size()){
            ans.push_back(nums);
            return;
        }

        for (int i = ind ; i < nums.size() ; i++){
            swap(nums[i], nums[ind]);
            solve(ind+1, nums, ans);
            swap(nums[i], nums[ind]);
        }
    }
};


