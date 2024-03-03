// Idea : we have a mod value given over here, and that confirms that we
// wont ever reach a value beyond that, this gives us clue to make use of 
// some way to reach somewhere like we have for dijkstra algo where we
// calculate the shortest path, here instead of path, we need to have the
// min number of steps, idea can be mapped to that used in dijkstra's algo
// we make use of queue in order to store the elem and the corresponding
// min steps to reach it, we keep traversing to the other elements && 
// keep updating the min steps to reach to the element required, also in
// the middle of all this, we keep checking before exploring other nodes 
// whether we have reached our destination or not 
// TC is same as dijkstra : O(100000) as max the queue can contain is 
// all the elements, 
// SC = O(100000)

int minimumMultiplications(vector<int>& arr, int start, int end) {
    vector<int>dist(100000, 1e9);
    queue<pair<int,int>>q ;
    q.push({start,0});
    dist[start] = 0 ;
    
    int mod = 100000;
    while(!q.empty()){
        int node = q.front().first;
        int steps = q.front().second;
        if (node == end) return steps ;
        q.pop();
        
        for(auto x: arr){
            int val = (x*node) % mod ;
            if (dist[val] > steps + 1 ){
                dist[val] = steps + 1 ;
                q.push({val, steps+1});
            }
        }
    }
    return -1;
}