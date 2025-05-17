// Idea : use min heap of size k , the top element with be the kth largest elem 
// when you have the last set of k elem, all the elem after the first are large only and the 
// first one can be rightly said as the kth largest element
// optimization: if an elem is smaller than the current top of pq and the queue is already full
// then pushing a smaller elem makes no sense as one of the elem has to be popped off to maintain 
// the length equal to k , and clearly it is the smallest elem that is popped off

// TC = O((n-k)logk)
// SC = O(k)


class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>pq ;
    int sz ;
    KthLargest(int k, vector<int>& nums) {
        sz = k ;
        for(auto x : nums){
            if (pq.size() < k)
                pq.push(x);
            else if (pq.top() < x) {
                pq.push(x);
                if (pq.size() > k) pq.pop();
            }
        }
    }
    
    int add(int val) {
        if (pq.size() < sz)
            pq.push(val);
        else if (pq.top() < val){
            pq.push(val);
            pq.pop() ; // already this is when size == k , 
            // so an elem has to be popped out
        }
        return pq.top();
        
    }
};