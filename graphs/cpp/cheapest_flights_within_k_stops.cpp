// the idea is same as the one used in dijkstra's algo except that we dont need to use priority queue
// as stops have to be prioritized over cost , so stops increase linearly as we move to the next level
// so no point of using the pq, Also additionally note that even if you reach destination node , before
// lets say the max num of stops , you can still explore cheaper options , so we dont stop here 
// TC = O(E), where E = flights.size()
// SC = O(E) 


int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    // make adjacency list first
    vector<vector<pair<int,int>>>adj(n);
    for(auto x : flights){
        adj[x[0]].push_back({x[1], x[2]});
    }


    vector<int>dist(n, 1e9);
    dist[src] = 0;
    queue<pair<int,pair<int,int>>>q ; // format : [stops, {node, dist}]
    q.push({0,{src,0}});

    while(!q.empty()){
        auto x = q.front() ;
        q.pop();
        int stops = x.first ;
        int node = x.second.first;
        int cost = x.second.second ;
 
        // Dont stop here even if the dest is reached as you might find a better price within the given no. of stops
        // the first criteria for queue is also no. of stops , so you might find better cost in subsequent entries in q
        
        if (stops > k) continue ;
        for(auto it: adj[node]){
            int adjN = it.first ;
            int edgeW = it.second ;

            if (cost + edgeW < dist[adjN] && stops <= k){// k included to consider this as last possibility
                dist[adjN] = cost + edgeW;
                q.push({stops+1, {adjN, dist[adjN]}});
            }
        }
    }
    if (dist[dst] == 1e9) return -1 ;
    return dist[dst] ; 
}