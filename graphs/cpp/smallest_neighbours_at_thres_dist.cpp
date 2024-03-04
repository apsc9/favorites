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