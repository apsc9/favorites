// Approach 1 : use a set so as to avoid duplicate triplets 
// the idea is to iterate two loops and keep on searching for the sum 0 , this has to be done 
// on  a sorted array

// this method adds an additional overhead of copying from set to vector in the end
// this extra time can somewhat be saved by checking the duplicate adjacent elements 
vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>>st;

    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>>ans ;

    for (int i = 0 ; i < n ; i++){
        int l = i+1, r = n-1 ;

        
        while(l < r){
            int sum = nums[i]+ nums[l]+ nums[r];
            if (sum == 0){
                st.insert({nums[i], nums[l], nums[r]});
                l++;
                r--;
            }
            else if (sum < 0)
                l++;
            else 
                r--;
        }
    }

    for (auto x : st){
        ans.push_back(x);
    }
    return ans;
}

// Approach 2 : use vector only and check for the adjaceent same items, this way you will save 
// the extra ds of set and the additional time of copying from one to another

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>>ans;

    sort(nums.begin(), nums.end());

    for (int i = 0 ; i < n ; i++){
        // to handle the case like : { -3, -1, -1, 0 , 1, 2}
        // to ensure that there are no duplicates in the final answer
        // we let the check after 0th iter as it covers the case : [0,0,0]
        if (i > 0 && nums[i] == nums[i-1])
            continue;
        
        int l = i+1, r = n-1 ;
        while(l < r){
            int sum = nums[i] + nums[l] + nums[r];
    
            if (sum == 0){
                ans.push_back({nums[i], nums[l], nums[r]});
                while(l < r && nums[l] == nums[l+1]) l++;
                while(l < r && nums[r] == nums[r-1]) r-- ; 

                l++;
                r--;
            }
            else if(sum < 0)
                l++;
            else 
                r--;
        }
    }
    return ans;
}

