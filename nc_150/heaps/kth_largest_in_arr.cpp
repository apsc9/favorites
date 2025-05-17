// use minheap:

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>pq ;

        for (auto& x: nums){
            pq.push(x);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};

// use quickselect algo 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0 , right = n-1;
        int val ;
        while(1){
            int index = partition(nums, left, right);
            if (index == n-k){
                val = nums[index];
                break;
            }

            if (index < n-k)
                left = index + 1 ;
            else 
                right = index - 1;
            
        }
        return val;
    }

    int partition(vector<int>&nums, int low, int high){
        int pivot = nums[high];
        int i = low - 1 ;

        for (int j = low; j < high; j++){
            if (nums[j] < pivot) {
                i++;
                swap(nums[i], nums[j]);
            }   
        }
        swap(nums[i+1], nums[high]);
        return i+1;
    }
};