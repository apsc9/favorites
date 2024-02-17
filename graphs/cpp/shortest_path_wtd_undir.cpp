// print shortest path in a weighted undirected graph :
// we will make use of dijkstra's algo here 
// This is an extension to standard algo, here we also 
// try to store the parent of eaach node so that we can keep 
// a track of the path where we came from 
// Overall TC is O(ElogV) + O(V)
// SC = O(V) for extra vectors used 

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges){
    // lets make adjacency list first : format {node, wt}

    vector<pair<int,int>>adj[n+1] ; 
    for (auto i: edges){
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});


        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq ;

        vector<int>dist(n+1, 1e9), parent(n+1);
        for(int i = 1 ; i <= n ; i++){
            parent[i] = i ;
        }

        dist[1] = 0 ;

        while(!pq.empty()){
            auto it = pq.top() ;
            pq.pop();
            int d = it.first ;
            int node = it.second;

            for(auto x: adj[node]){
                int adjNode = x.first ;
                int edgewt = x.second;

                if (dist[adjNode] > d + edgewt){
                    parent[adjNode] = node ;
                    dist[adjNode] = d+ adgewt ;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        if (dist[n] == 1e9) return {-1};

        vector<int>path ;
        int val = n ;
        
        // takes o(n) in worst case when the path is linear
        while(parent[val] != val){
            path.push_back(val) ;
            val = parent[val];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
}
