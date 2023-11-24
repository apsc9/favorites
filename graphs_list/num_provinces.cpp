// problem Link : https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces

// the idea is to simply convert the given adjacency matrix into adj list 
// and find the number of connected components in a graph, this is simply applying 
// bfs or dfs which will take O(E+V) time

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        
        vector<vector<int>> list(V+1);
        for (int i = 0 ; i < V ; i++){
            for(int j = 0 ; j < V; j++){
                if (adj[i][j] == 1 && i != j){
                    list[i].push_back(j);
                    list[j].push_back(i);
                }
            }
        }
        
        vector<int>vis(V+1,0);
        int ans = 0 ;
        
        for(int i = 0 ; i < V ; i++){
            if(vis[i] == 0){
                ans++;
                dfs(i, list, vis);
            }
        }
        
        return ans;
    }
    
    void dfs(int u, vector<vector<int>>&adj, vector<int>&vis){
        vis[u] = 1 ;
        for(auto v:adj[u]){
            if(vis[v] == 0)
                dfs(v, adj, vis);
        }
    }
};