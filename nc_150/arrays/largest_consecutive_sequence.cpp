// Prob Link : https://leetcode.com/problems/longest-consecutive-sequence/description/
// Approach 1 : sorting 
// sort the elements of the array first and then check the longest common sequence
// TC = O(nlogn)
// SC = O(1)

int longestConsecutive(vector<int>&nums){
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int mxlen = 0, curlen = 1 ;
    for(int i = 1 ; i < n ; i++){
        if (arr[i] == arr[i-1] + 1){
            curlen++;
        }
        else if (arr[i] != arr[i-1] + 1){
            mxlen = max(mxlen, curlen);
            curlen = 1;
        }
    }
    mxlen = max(mxlen, curlen);
    return mxlen;
}

// Approach 2 : using maps 
// the idea here is to keep track of only those elements which mark the beginning of some 
// continuous subsequence, and keep the track of max len of that subseq
// To mark such elem we can simply do 2 traversals of the map, 
// in the first one, we can just store everything on the map and in the second one we can see 
// whether for every elem do we have elem-1 in the map, if not we can just leave it as marked
// else we can remove that 1 and make it to 0
//  this way we can be sure that we are only keeping track of only those elem which are the actual 
// starting point of some subsequence , this way time complexity will also be linear
// TC = O(n) ; only three traversals of the map : O(n + n + n) = O(3*n)
// SC = O(n) ; for map 

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int,int>m;
    for(int i = 0; i < n ; i++){
        m[nums[i]]++;
    }

// letting only those elem as marked which are the actual starting point of some sequence
    for (int i = 0; i < n ; i++){
        if (m.count[nums[i] -1] > 0)
            m[nums[i]] = 0 ;
    }

    int mx = 0;
    for (auto x : nums){
        if (m[x] > 0){
            int cnt =  1;
            while(m.count[x+cnt] > 0)
                cnt++;
            mx = max(mx, cnt);
        }
    }
    return mx ;
}

