// We need to have unique pairs in the final answer and that too in a particular order
// in order to do so, we need to handle the case which could lead to duplicates.

// TC = O(2^n * k)
// if all elem are unique, then num of subsequences will be O(2^n). we also add the 
// temp arr to final ans, when we reach the base condition which takes K : avg space for temp

// SC = O(k*x)
// for x combination, we will have space x*k where k is avg len of the combination.

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>>ans;
    vector<int>tmp ;
    solve(0, target, candidates, ans, tmp);
    return ans;
}

void solve(int ind, int target, vector<int>&arr, vector<vector<int>>&ans, vector<int>&tmp){
    if (target == 0){
        ans.push_back(tmp);
        return;
    }

    for(int i = ind; i < arr.size(); i++){
        if(i > ind && arr[i] == arr[i-1]) continue ;
        if (arr[i] > target) break ;

        tmp.push_back(arr[i]);
        solve(i+1, target - arr[i], arr, ans, tmp);
        tmp.pop_back();
    }
}