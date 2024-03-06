// Approach1 : Using floyd warshall :
// the idea can be found from the hint that it is being asked to look at the 
// dist for each of the ndde , and also threshold distance is given
// this makes it clear that it is going to be a multi source shortest 
// path algorithm , note that you simply have to form the matrix just 
// like in floyd warshall and try to find the city having min neighbours 
// below threshold given , so we use Floyd Warshall as base and extend it 
// a bit , also take care that we have included self loops as well

// TC = O(n^3)
// SC = O(n^2)

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>>adj(n, vector<int>(n,1e9));
    
    for(auto x : edges){
        adj[x[0]][x[1]] = x[2];
        adj[x[1]][x[0]] = x[2];
    }
    
    for(int i = 0 ; i < n ; i++) adj[i][i] = 0;
    for(int k = 0 ; k < n ; k++){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if (adj[i][k] == 1e9 || adj[k][j] == 1e9)
                    continue;
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
    
    // vector<int>ways(n,0);
    // for(int i = 0 ; i < n ; i++){
    //     for(int j = 0 ; j < n ; j++){
    //         if (adj[i][j] <= distanceThreshold )
    //             ways[i] ++;
    //     }
    // }
    
    // int city ;
    // int min_val = INT_MAX;
    // for(int i = 0 ; i < n ; i++){
    //     if (ways[i] != 0 && min_val >= ways[i]){
    //         min_val = ways[i] ;
    //         city = i ;
    //     }
    // }
    // return city ;

    int citycount = n ;
    int city = -1 ;

    for (int i = 0 ; i < n ; i++){
        int cnt = 0 ;
        for(int j = 0 ; j < n ; j++){
            if (adj[i][j] <= distanceThreshold)
                cnt++;
        }
        if (cnt <= citycount){
            citycount = cnt ;
            city = i ;
        }
    }
    return city ;
}


// Approach 2: using Dijkstra 
// as dijkstra is a single source shortest path algo, so we make use of it
// to find the distance with each node as the source , once we have that for
// every node, we can see the smallest neigbours at a threshold by iterating
// over all the other nodes as source 
// TC is a lot better here as not it is O(V*ElogV) + O(V*V)

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<pair<int,int>>>adj(n);

    // lets make adj list first ;
    for (auto x : edges){
        adj[x[0]].push_back({x[1], x[2]});
        adj[x[1]].push_back({x[0], x[2]});
    }
    
    vector<int>arr(n);
    int city = -1 , city_max = n ;
    for (int i = 0 ; i < n ; i++){
        arr = solve(i, adj);
        int cnt = 0 ;
        for (int j = 0 ; j < n ; j++){
            if (arr[j] <= distanceThreshold)
                cnt++;
        }
        if (cnt <= city_max){
            city_max = cnt ;
            city = i ;
        }
    }

    return city ;
}

vector<int>solve(int s, vector<vector<pair<int,int>>>&adj){
    int n = adj.size();
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    vector<int>dist(n, 1e9);
    dist[s] = 0;
    pq.push({0,s});

    while(!pq.empty()){
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto x : adj[node]){
            int adjN = x.first;
            int adjW = x.second;

            if (dist[adjN] > wt + adjW){
                dist[adjN] = wt + adjW ;
                pq.push({dist[adjN], adjN});
            }
        }
    }
    return dist;
}