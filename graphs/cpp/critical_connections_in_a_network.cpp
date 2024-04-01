// this is implementation of tarjan's algo
// here the basic idea is to keep track of the time where every node is reached the
// first time and also another array is used called low which gives min time for 
// insertion in any adjacent node except parent
// the idea is to see whether we can disconnect any edge and still there is a 
// possible connection between the 2 nodes
// so the idea here is , if an adjacent node is visited, then already there is 
// a path to reach it , so cant be a bridge, 
// if an adjacent node has time greater than the min time of insertion for a node
// then that edge constitutes a bridge


// TC : O(V+2E) , for dfs traversal
// SC : O(V+2E) + O(3N)


class Solution {
private:
    int timer = 1 ;
private:
    void dfs(int node, int parent, vector<int>& low, vector<int>&tin, vector<int>&vis,
    vector<vector<int>>&ans, vector<vector<int>>&adj){
        vis[node] = 1;
        tin[node] = low[node] = timer++;

        for (auto x : adj[node]){
            if (x == parent) continue ;
            if (!vis[x]){
                dfs(x, node, low, tin, vis, ans,adj);
                low[node] = min(low[node], low[x]);

                if (low[x] > tin[node]){
                    ans.push_back({x,node});
                }
            }
            else {
                low[node] = min(low[node], low[x]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for (auto x : connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<int>vis(n,0);
        vector<int>tin(n) ; // stores the time of insertion during dfs
        vector<int>low(n); // min of all the adjacent nodes except the parent 
        vector<vector<int>>ans ;
        dfs(0,-1,low, tin, vis, ans, adj);
        return ans;
    }
};