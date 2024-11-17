// Approach 1 : just store it in terms of index, time 
// track back from rev direction, if you find time greater than the curr one , you have 
// got a fleet, update the current max , else continue traversing 
// Here the arr was itself sorted as we were using the distances as index 

// TC = O(target)
// SC = O(target)
int carFleet(int target, vector<int>& pos, vector<int>& speed) {
    vector<double>arr(target);
    int n = pos.size();
    for (int i = 0; i < n ; i++){
        arr[pos[i]] = double (target - pos[i]) / speed[i];
    }
    int ans = 0 ;
    double prev = 0;
    for (int i = target - 1 ; i >= 0 ; i--){
        if (arr[i] > prev){
            prev = arr[i];
            ans++;
        }
    }
    return ans ;
}

// Approach 2 : use stack after sorting with the same concept as above

int carFleet(int target, vector<int>& pos, vector<int>& speed) {
    int n = pos.size();
    vector<pair<int, int>>arr(n);

    for (int i = 0 ; i < n ; i++){
        arr[i] = {pos[i], speed[i]};
    }

    sort(arr.begin(), arr.end());
    stack<double>st;

    for(auto itr = arr.rbegin() ; itr != arr.rend() ; itr++) {
        double dist = target - itr->first;
        double time = (double)dist/itr->second;
        if (st.empty() || time > st.top())
            st.push(time);
    }
    return st.size();

    
}

