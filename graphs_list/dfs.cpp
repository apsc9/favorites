// Problem Link : https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=dfs_of_graph
// This is just basic dfs traversal code, nothing fancy, no application involved

public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>vis(V+1, 0);
        vector<int>ans;
        
        dfs(0,adj, vis, ans);
            
        return ans;
    }
    
    void dfs(int u, vector<int> adj[], vector<int>&vis, vector<int>&ans){
        vis[u] = 1 ;
        ans.push_back(u);
        
        for(auto v: adj[u]){
            if (vis[v] == 0)
                dfs(v, adj, vis, ans);
        }
    }
    
    // TC = O(N) + O(2E)
    // SC = O(N) + O(N) + O(N) (storage as well as recursion stack which in worst case can go to O(N) in case of skewed tree)
    
    