// Problem Link : https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/
// For soln refer this link : https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/solutions/2721045/best-solution-tabulation-failed-full-explaination-c/

// Idea use meet in the middle and use references else it will hit TLE 
// TC = O(1) + O(n* 2^n + n* 2^n ) + O(2^n * log(2^n)) + O(2 ^ (n/2) log (2^n/2))
//      divide   generate subarr sum     finding elem      sorting (simplified based on assumption)

int minimumDifference(vector<int>& nums) {
    int n = nums.size() ;
    int N = n/2 ;
    int sum = accumulate(nums.begin(),nums.end(), 0);

    vector<vector<int>> left(N+1), right(N+1);

    // generate subsets sum for both the sub arrays 
    for (int mask = 0 ; mask < (1 << N); mask++){
        int ind = 0, lsum = 0 , rsum = 0 ;
        for (int i = 0 ; i < N ; i++){
            if (mask & (1 << i)){
                ind++;
                lsum += nums[i];
                rsum += nums[i+N];
            }
        }
        left[ind].push_back(lsum);
        right[ind].push_back(rsum);
    }

    // sorting the right array so that the val can be found using bin search from that
    for (int i = 0 ; i <= N ; i++){
        sort(right[i].begin(), right[i].end());
    }

    // lets try to find the min now ;
    int res = INT_MAX; 

    for (int ind = 0 ; ind <= N ; ind ++){
        for (auto &a: left[ind]){
            int b = (sum - 2*a)/2 ; // val to be found from the right
            int rtind = N -ind ; // finding the index , if left subarray took i elem , rest will be from right
            auto &v = right[rtind];

            auto itr = lower_bound(v.begin(), v.end(), b); // find the lower bound using bs

            if (itr != v.end())
                res = min(res, abs(sum - 2*(a + (*itr)))); 
        }
    }
    return res;
}