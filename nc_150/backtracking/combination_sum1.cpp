// Use Recursion: try the concept of pick and not-pick

// tc = O(2^t *k) where t : target, k : avg len of every combination generated
// if one elem has to be picked only once, every elem could have been picked/ not picked
// that would have given 2^n, but here that is not the case
// assume that elem is 1 and target is 10, so for 10 times you have the choice whether to pick or not
// SC = O(k*x) , where k: avg len, x: num of combinations

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int>temp ;
        solve(0, target, candidates, temp, ans);
        return ans;
    }

    void solve(int ind, int target, vector<int>&candidates, vector<int>&temp, vector<vector<int>>&ans){
        if (target == 0){
            ans.push_back(temp);
            return ;
        }
        if (target < 0 || ind == candidates.size()) return ;

        temp.push_back(candidates[ind]);
        solve(ind, target - candidates[ind], candidates, temp, ans);
        temp.pop_back();
        
        solve(ind+1, target, candidates, temp, ans);
    }
};

