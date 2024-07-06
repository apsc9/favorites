// using vector and map : 
// here you are storing nums with freq just like we have in map
// now vector has (values, count) in it
// we use a custom sort function to sort it on the basis of counts
// the result will already have vect of pairs sorted in order of freq
// so just pop out the first k elem from the sorted vector of pairs


static bool comp (pair<int,int>&a , pair<int,int>&b){
    return a.second > b.second ;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int>m;
    vector<pair<int,int>>vec ;

    for (auto x: nums){
        m[x]++;
    }

    for(auto x: m){
        vec.push_back(x);
    }

    sort(vec.begin(), vec.end(), comp);
    vector<int>ans;
    for(int i = 0; i < k ; i++){
        ans.push_back(vec[i].first);
    }
    return ans;
}

// using priority queue: priority queue also solves the same purpose as above solution
// TC = O(n * log(n-k))
vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int>ans;
    unordered_map<int,int>m;
    for (auto x: nums){
        m[x]++;
    }

    priority_queue<pair<int,int>>pq ;

    for (auto x: m){
        pq.push(make_pair(x.second, x.first)); // freq, num
        if (pq.size() > m.size() - k){ // say m.size() =5 , k = 3 , so if pq has 
        // more than 2 elements, and total elem are 5, then you already have one element
        // atleast out of those 3 elem(k) that you need , so as per the current state of 
        // queue, you can have atleast one elem in your answer
            ans.push_back(pq.top().second);
            pq.pop();
        }
    }
    return ans;
}

// Using bucket sort and map : the idea is to store the frequency of each number 
// then create a new vector with freq as index and the corresponding nums as values
// then in order to get the top elements, iterate from the back till k = 0
// TC = O(n) , SC = O(n)

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int>m;
    vector<int>ans ;

    for (auto x: nums){
        m[x]++;
    }

    vector<vector<int>>buckets(nums.size()+1);
    for (auto x: m){
        buckets[x.second].push_back(x.first);
    }

    for (int i = buckets.size()-1 ; i >= 0 ; i-- ){
        if(buckets[i].size() != 0){
            for (auto x : buckets[i]){
                ans.push_back(x);
                if (ans.size() == k) return ans ;
            }
        }
    }
    return ans;
}