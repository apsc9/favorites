// #1. use maxheap : 

class Twitter {
public:
    unordered_map<int,unordered_set<int>>fo ;
    unordered_map<int, vector<pair<int,int>>> tweet ;
    long long time;
    Twitter() {
        time = 0 ;
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq ;

        // put user's tweet into the pq first 
        for (auto x= tweet[userId].begin(); x != tweet[userId].end(); x++){
            pq.push(*x);
        }
        // now try to get the tweets from the followers of user
        for (auto x = fo[userId].begin(); x != fo[userId].end(); x++){
            int usr = *x ;
            for (auto y= tweet[usr].begin(); y != tweet[usr].end(); y++){
                pq.push(*y);
            }
        }

        vector<int> ans ;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            if (ans.size() == 10)
                break ;
        }
        return ans ;
    }
    
    void follow(int followerId, int followeeId) {
        fo[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fo[followerId].erase(followeeId);
    }
};

// #2. use minheap : (easy to understand)
// but for a large number of tweets, this is inefficient

class Twitter {
public:
    unordered_map<int,unordered_set<int>>fo ;
    unordered_map<int, vector<pair<int,int>>> tweet ;
    long long time;
    Twitter() {
        time = 0 ;
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq ;

        for(auto x: tweet[userId]){
            pq.push(x);
            if (pq.size() > 10)
                pq.pop();
        }

        for (auto follower: fo[userId]){
            for (auto twt: tweet[follower]){
                pq.push(twt);
                if (pq.size() > 10) pq.pop();
            }
        }
        

        vector<int> ans ;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            if (ans.size() == 10)
                break ;
        }
        reverse(ans.begin(), ans.end());
        return ans ;
    }
    
    void follow(int followerId, int followeeId) {
        fo[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fo[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */


// #3. using minheap and count variable (optimized)

class Twitter {
public:
    unordered_map<int,unordered_set<int>>fo ;
    unordered_map<int, vector<pair<int,int>>> tweet ;
    long long time;
    Twitter() {
        time = 0 ;
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq ;
        int cnt = 0;
        for(auto x = tweet[userId].rbegin(); x != tweet[userId].rend(); x++){
            cnt ++;
            pq.push(*x);
            if (pq.size() > 10)
                pq.pop();
            
            if (cnt == 10)
                break ;
        }

        for (auto follower: fo[userId]){
            cnt = 0 ;
            for (auto x= tweet[follower].rbegin(); x != tweet[follower].rend(); x++){
                cnt++;
                pq.push(*x);
                if (pq.size() > 10) pq.pop();
                if (cnt == 10) break ;
            }
        }
        vector<int> ans ;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            if (ans.size() == 10)
                break ;
        }
        reverse(ans.begin(), ans.end());
        return ans ;
    }
    
    void follow(int followerId, int followeeId) {
        fo[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fo[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

