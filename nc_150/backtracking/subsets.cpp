// idea: make use of bit manipulation in order to get the power set of the given set of nums
// explore all the possible combinations and from them go through each bit, check whether 
// each bit is set or not, if set, just include it in your answer, go iteratively for the num
// of bits sets and store in the list 

// TC = O(n* 2^n)
// SC ~= O(2^n * n)

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();

    vector<vector<int>>ans;

    for(int num = 0; num < (1<<n); num++){
        vector<int>temp;
        for(int i = 0; i < n ; i++){
            if (num & (1 << i))
                temp.push_back(nums[i]);
        }
        ans.push_back(temp);
    }
    return ans;
}

// Recursion method : 

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>tmp;
        vector<vector<int>>ans;
        solve(0, nums, tmp, ans);
        return ans;
    }

    void solve(int ind, vector<int>&nums, vector<int>&tmp, vector<vector<int>>&ans){
        if (ind == nums.size()){
            ans.push_back(tmp);
            return;
        }

        tmp.push_back(nums[ind]);
        solve(ind+1, nums, tmp, ans);
        tmp.pop_back();
        solve(ind+1, nums, tmp, ans);
    }
};

