// Bellman ford is able to detect negative weight cycle as well, applicable 
// for directed graph, 
// Relax all the edges N-1 times and update the distances,
// Why N-1 : because in worst case the starting source edge might be towards 
// the end , take linear example : 0 -> 1 -> 2 -> 3 -> 4 , each w/ edge wt=1
// After the above step, just relax all the edges nth time as well
// if for any node the distance is further reduced, then there is negative 
// edge weight cycle 

// TC = O(VE)
// SC = O(V)



vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    vector<int>dist(V, 1e8);
    dist[S] = 0 ;
    
    for(int i = 0 ; i < V-1 ; i++){
        for(auto x : edges){
            int u = x[0] ;
            int v = x[1] ;
            int wt = x[2] ;
            
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt ;
        }
    }
    
    // relaxing nth time to see if dist can be further reduced for 
    // any vertex, in that case there is a negative edge cyclw
    
    for (auto x : edges){
        int u = x[0] ;
        int v = x[1] ;
        int wt = x[2] ;
        
        if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            return {-1};
    }
    
    return dist ;
}