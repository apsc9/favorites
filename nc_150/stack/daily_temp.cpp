// Idea is to use concept of monotonically decreasing stack 
// TC = o(n)
// SC = o(n)

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int>ans(n, 0) ;
    stack<pair<int,int>>s ;

    // for (int i = n-1 ; i >= 0; i--){
        
    //     while(!s.empty() && s.top().first <= temperatures[i])
    //         s.pop();

    //     if (s.empty()) ans[i] = 0 ;
    //     else ans[i] = s.top().second - i ;

    //     s.push({temperatures[i], i});
    // }

    for (int i = 0; i < n ; i++){
        while(!s.empty() && temperatures[i] > s.top().first){
            int t = s.top().first;
            int ind = s.top().second ;
            s.pop();

            ans[ind] = i - ind ;
        }
        s.push({temperatures[i], i});
    }
    return ans;
}