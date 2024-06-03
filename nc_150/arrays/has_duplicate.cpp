// Problem Link : https://leetcode.com/problems/contains-duplicate/description/

// Method 1 : brute force - use 2 for loops , check if you find any duplicate elements
// TC = O(n^2)

// Method 2 : use sorting 
// sort the array first and then see if the 2 adjacent elements are the same or not
// TC = O(nlogn)

// Method 3 : use hashset 
// TC = O(n)

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int>s ;
    for (auto x: nums){
        if (s.count(x) >= 1)
            return true;
    }    
    return false ;
}

// Method 4 : use hashmap
// TC = O(n)

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int,int>m;
    for (int i = 0 ; i < nums.size() ; i++){
        if (m[nums[i]] >= 1)
            return true ;
        m[nums[i]]++;
    }
    return false;
}