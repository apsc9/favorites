// Idea is to make use of topo sort here : as toposort guarantees a particular
// order in which nodes can be traversed, basically it gives you the 
// path to reach to any particular node and out of those paths select the 
// best possible path, so topo sort works here 

// Method : 2 steps involved
// 1. Find topo sort for the given DAG
// 2. Using that toposort order, try to find the min distance to reach every 
// node using the best possible path 

// TC =O(n+m) for toposort as well as calc the min dist
// SC = O(n+m) for adjacency list , recursion stack can be O(n)

class Solution {
    
  private:
    void dfs(int node, vector<int>&vis, stack<int>&s, vector<vector<pair<int,int>>>&adj){
        vis[node] = 1 ;
        for (auto x: adj[node]){
            if (!vis[x.first])
                dfs(x.first, vis, s, adj);
        }
        s.push(node);
    }
    
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int,int>>>adj(N);
        
        for(int i = 0 ; i < M ; i++){
            int u = edges[i][0] ;
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
        }
        
        vector<int>vis(N,0);
        stack<int>s;
        
        // simple topo sort : O(n+m)
        for(int i = 0 ; i < N ; i++){
            if (!vis[i])
                dfs(i,vis,s,adj);
        }
        
        // find out the min dist to reach every node
        
        vector<int>dist(N, 1e9);
        dist[0] = 0 ;
        
        // O(n+m) as this will also only cover all the edges for each node
        // basically adjacency list will be covered(stack gives n, in total it will
        // cover number of edges only)
        while(!s.empty()){
            int node = s.top() ;
            s.pop();
            
            for(auto x: adj[node]){
                int side = x.first ;
                int wt = x.second;
                
                if (dist[side] > dist[node] + wt)
                    dist[side] = dist[node] + wt;
            }
            
        }
        
        for(int i = 0 ; i < N ; i++){
            if (dist[i] == 1e9)
                dist[i] = -1 ;
        }
        return dist ;
    }
};