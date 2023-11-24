// Problem Statement : https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bfs_of_graph

// basic bfs code 
// TC = O(V+E)
// SC = O(V) for storage used for queue

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int>ans ;
    
    vector<int>vis(V+1,0);
    queue<int>q ;
    
    q.push(0);
    vis[0]= 1 ;
    
    while(!q.empty()){
        int u = q.front(); q.pop();
        ans.push_back(u);
        for(auto v: adj[u]){
            if(vis[v] == 0){
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    
    return ans ;
}