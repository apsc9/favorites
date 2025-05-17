// make use of max-heap :
// consider it as a cycle of time: n+1, 
// make the CPU round robin between the most popular tasks at any time
// for every cycle, pop the most occuring elem first and try to fill the places
// after the cycle ends, just decrement their count and put them back in pq

// if pq is not empty then it means something is still there , implies that 
// the full cycle has come into swing ,but when in the end pq is empty 
// it means all the elem are used up , so we take the local count only


int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char,int>mp;
    for(auto& x : tasks){
        mp[x]++;
    }

    priority_queue<int>pq ;
    for(auto& x: mp){
        pq.push(x.second);
    }

    int total = 0 , cycle = n+1 ;
    while(!pq.empty()){
        int interval = 0 ;
        vector<int>tmp ;
        for(int i= 0 ; i < cycle ; i++){
            if (!pq.empty()){
                tmp.push_back(pq.top());
                pq.pop();
                interval++;
            }
        }
            for(auto x: tmp){
                if (--x){
                    pq.push(x);
                }
            }
        
        total += !pq.empty() ? cycle : interval ;
    }

    return total ;
}

// Ideation of a formula/concept : 

// if there are m tasks that appear n times and are separated by k steps, 
// then total steps taken will be :
//  (n-1)*(k+1) + m , m <= k
//  if m > k , then it will be size(arr); 

int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char,int>mp ;

    int mxcnt = 0 ;
    for(auto& x: tasks){
        mp[x]++;
        mxcnt = max(mxcnt, mp[x]);
    }
    int ans = (mxcnt-1)* (n+1);
    for(auto& x: mp){
        if (x.second == mxcnt)
            ans++;
    }

    return max((int)tasks.size(), ans);
}