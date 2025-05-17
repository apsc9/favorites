// Approach1 : max heap 
// keep only the k elem in the maxheap, as the size exceeds k, just pop an elem out 
// popped elem will be the largest elem, hence in the end, only the smallest k elem remain

// use max heap : TC = O(Nlogk)
// SC = O(k)

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    auto dist = [] (auto &x) { return x[0] * x[0] + x[1] * x[1];};
    priority_queue<pair<int,int>> pq ;

    for (int i = 0; i < points.size(); i++){
        pq.emplace(dist(points[i]), i);
        if (pq.size() > k)
            pq.pop();
    } 

    vector<vector<int>>ans;
    for (int i = 0; i < k ; i++){
        ans.push_back(points[pq.top().second]);
        pq.pop();
    }
    return ans ;

}

// same as above, just slight variation in implmntn
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    auto dist = [](auto& x) { return x[0]*x[0] + x[1]*x[1] ;};
    auto comp =[&](auto& a, auto&b) { return dist(a) > dist(b);};
    make_heap(begin(points), end(points), comp);

    // making heap takes O(N) time
    // now time to pop first k elem 
    // time = klogN

    vector<vector<int>>ans;
    for (int i = 0;i < k ; i++){
        ans.push_back(points[0]);
        pop_heap(begin(points), end(points), comp);
        points.pop_back();
    }
    return ans ;
}

// Approach 2 : use min heap : the idea is to make a minheap and pop out first k elem from the heap
// TC = O(N) + O(klogN) , make the heap and popping k elem from the heap
// SC = O(N)

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>>minHeap ;

    for(auto& x: points){
        int a = x[0], b = x[1];
        minHeap.push_back({-a*a -b*b, a, b});
        // default would have been maxheap, now it is neg val, so will be minheap
    }

    make_heap(minHeap.begin(), minHeap.end());
    vector<vector<int>>ans;

    for(int i = 0; i < k ; i++){
        auto& x = minHeap[0];
        ans.push_back({x[1], x[2]});
        pop_heap(minHeap.begin(), minHeap.end());
        minHeap.pop_back();
        
    }
    return ans ;
}
