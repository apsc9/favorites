// the idea comes from the fact that we can try to figure out an optimum value for we 
// koko can eat within the given time, and it can start from 1 and go till max val
// so we apply binary search on this range that could be possible

// TC = O(nlogM) , n : num of piles, M is the range of k(left to right)
// SC = O(1)

int minEatingSpeed(vector<int>& piles, int h) {

        int l = 1;
        int r = 1e9;

        while (l < r){
            int mid  = l + (r-l)/2;
            if (within_time(piles, mid, h)) r = mid ; // to incr the val, u need a lower num 
            else l = mid+1 ;  // to decrease val, you need a higher num
        }
        return l ;
    }

    bool within_time(vector<int>&nums, int mid, int h){
        int time = 0 ;
        for (auto num: nums){
            time += num/mid ;
            if (num% mid) time += 1 ;
        }
        return time <= h;
    }