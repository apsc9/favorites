// Idea : the  intuition behind using deque is that if you reach and element say arr[i] in a 
// window, then any element lesser than that cant be taken, that is the reason why we are storing
// it i nn decreasing fashion so  that any smaller element can be removed from the back of the 
// queue which is lesser than the current elem , that way max elem will always be in the front

// the implementation is with the inline code 
// TC = O(n) + o(n) , one for iteration and one for removal 
// SC = o(k), at max you can store is the size of the window

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int>dq ;
    vector<int>ans;

    for (int i = 0 ;i < nums.size(); i++){
        if (dq.front() == i-k) dq.pop_front(); // remove the out of bound index

        // now try to remove the smaller elements from the queue so that 
        // we always have the max elem in the front
        while(!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        // lets push every index onto the queue
        dq.push_back(i);
        if (i - k + 1 >= 0) 
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}