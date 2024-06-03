// Problem Link :

// approach 1: brute force 
// use 2 for loops to check if the 2 add up to sum given or not
// TC = O(n^2)

// approach 2: use sorting 
// sort the arr first(use temp arr), then try to use 2 pointer approach and store the index
// find the index of the numbers which make up the target and return their indices
// TC = O(nlogn)

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int>temp(nums), ans ;
    sort(temp.begin(), temp.end());
    int n = nums.size();
    int l = 0 , r = n-1 , ind1 = 0, ind2 = 0 ;

    while(l < r){
        if (temp[l] + temp[r] == target){
            ind1 = temp[l] , ind2 = temp[r] ;
            break ;
        }
        else if (temp[l] + temp[r] < target)
            l++;
        else 
            r--;
    }

    for (int i = 0 ;i < n ; i++){
        if (nums[i] == ind1)
            ans.push_back(i);
        else if (nums[i] == ind2)
            ans.push_back(i);
    }
    return ans;
}

// approach 3: use hashmap (optimized to use single pass)
// with every number see if there is another num which constitute the target
// else add the number to the hashmap 
// TC = O(n); SC = O(n)

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int>m;
    for (int i = 0 ; i < nums.size(); i++){
        int val = target - nums[i] ;
        if (m.find(val) != m.end())
            return {i, m[val]};
        m[nums[i]] = i ;
    }
    return { };
}