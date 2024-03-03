// Idea is to tweak dijkstra's algo a bit and use the priority queue 
// to find the nodes as per the distance, we put pair of dist , node into 
// the pq / min heap and keep popping out as per the min distance val
// The idea to reach a certain node is to traverse through that node where 
// dist travelled would be less, that is the same idea behind this approach
// Also we maintain a ways array where we store the num ways to reach the 
// node using min dist/time , if we found it the first time (way with min dist)
// we update it to be equal to ways[intermed_node] , else if we reach the same 
// min dist again , we update it to ways[given_node]+ways[intermed_node]
// TC = O(ElogV) , same as dijkstra
// SC = O(V) , extra space for ways , dist array

int countPaths(int n, vector<vector<int>>& roads) {

    vector<vector<pair<int, int>>>adj(n); // lets make adj list first
    for(auto x : roads){
        adj[x[0]].push_back({x[1], x[2]});
        adj[x[1]].push_back({x[0], x[2]});
    }

    vector<long long>dist(n, LONG_MAX);
    vector<int>ways(n, 0);

    ways[0] = 1 ;
    dist[0]= 0 ;
    priority_queue<pair<long long, int>, vector<pair<long long, int>> ,greater<pair<long long,int>>> pq ;
    // format : {time/dist, node}
    pq.push({0,0});

    int mod = (int) (1e9 + 7) ;
    while(!pq.empty()){
        long long dis = pq.top().first ;
        int node = pq.top().second;
        pq.pop();

        for(auto x : adj[node]){
            int adjN = x.first ;
            long long weight = x.second ;
            //cout << dist[node] << endl ;

            if (dist[adjN] > dis + weight){ // first time min dist found
                dist[adjN] = dis + weight ;
                ways[adjN] = ways[node] ;
                pq.push({dist[adjN], adjN});
            }
            else if (dist[adjN] == dis + weight){
                ways[adjN] = (ways[node] + ways[adjN]) % mod ;
            }
        }
    }
    return ways[n-1]%mod ;
}