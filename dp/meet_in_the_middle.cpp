// Problem link : https://leetcode.com/problems/closest-subsequence-sum/description/
// Closest Subsequence Sum
// Idea : 
// 1. the idea is to divide the arr into 2 parts and generate all possible sums within each of them
// 2. sort the sum in the second array, take the individual sums from the first array and apply binary 
// search to find the closest sum in the second array
// 3. Handle the index from the second half carefully (see what lower bound returns, handle both 
// the cases with wrt the index given by lower bound), return min val 

// TC 
// (for dividing first  arr) = 2^(n/2) + 2^(n/2)
// sorting the second arr = 2 ^ (n/2) log (2^n/2) = 2^(n/2) * n/2
// search time : 
//          binary search on sec arr = log 2^(n/2) = n/2
//          no. of times bin search is triggered = size of first arr = 2 ^(n/2)

// total time = generate + sort + search 
//            = 2^(n/2) + 2^(n/2) + n/2 * 2^(n/2) + 2^(n/2) 
//            = O(n*2^(n/2))

class Solution {
    vector<int>findAllSums(vector<int>&nums, int start, int end, int offset){
        int n = end - start + 1 ;
        vector<int>ans;
        for (int i = 0 ; i < (1 << n) ; i++){
            int sum = 0;
            for (int j = 0 ;j < n ; j++){
                if (i & (1 << j) )
                    sum += nums[offset + j];
            }
            ans.push_back(sum);
        }
        return ans;
    }
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();

        vector<int>first_half = findAllSums(nums, 0, n/2-1, 0);
        vector<int>second_half = findAllSums(nums, n/2, n-1, n/2);
        sort(second_half.begin(), second_half.end());

        int mini = INT_MAX ;
        for (int i = 0; i < first_half.size() ; i++){
            int val = goal - first_half[i];
            int index = lower_bound(second_half.begin(), second_half.end(), val) - second_half.begin();
            
            if (index > 0)
                mini = min(mini, abs(val - second_half[index-1]));
            if (index < second_half.size())
                mini = min(mini, abs(val - second_half[index]));
        }
        return mini;
    }
};