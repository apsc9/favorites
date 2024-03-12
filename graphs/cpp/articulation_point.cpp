// The difference in finding the lowest time of insertion in this problem is that 
// in the bridgealgorithm, we only excluded the parent node but in this algorithm, 
// we are excluding the visited nodes along with the parent node.
// To find out the bridges in the bridge problem, we checked inside the DFS, 
// if there exists any alternative path from the adjacent node to the current node.
// But here we cannot do so as in this case, we are trying to remove the current node 
// along with all the edges linked to it. For that reason, here we will check 
// if there exists any path from the adjacent node to the previous node of 
// the current node. In addition to that, we must ensure that the current node 
// we are trying to remove must not be the starting node. 
// If the node is a starting point we will check the number of children of the node. 
// If the starting node has more than 1 child(The children must not be connected), 
// it will definitely be one of the articulation points
// TC = O(V+2E) , bcoz of dfs
// SC = O(3V)

class Solution {
  private:
    int timer = 1;
    void dfs(int node, int parent, vector<int>&tin, vector<int>&low, vector<int>&vis,
    vector<int>&point, vector<int>adj[]){
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        
        int child = 0 ;
        for (auto x : adj[node]){
            if (x == parent) continue;
            if (!vis[x]){
                dfs(x,node,tin,low,vis,point,adj);
                low[node] = min(low[node], low[x]);
                if (low[x] >= tin[node] && parent!= -1){
                    point[node] = 1 ;
                }
                child++;
            }
            else {
                low[node] = min(low[node], tin[x]);
            }
        }
        if (child > 1 && parent == -1)
            point[node] = 1;
    }
    
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int>vis(V,0), point(V,0);
        vector<int>tin(V), low(V);
        
        for (int i = 0 ; i < V ; i++){
            if (!vis[i]){
                dfs(i,-1,tin, low, vis, point, adj);
            }
        }
        
        vector<int>ans;
        for (int i = 0 ; i < V ; i++){
            if (point[i] == 1){
                ans.push_back(i);
            }
        }
        
        if (ans.size() == 0) return {-1};
        return ans;
        
    }
};