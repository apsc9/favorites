class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i = 1 ; i <= n ; i++){
            parent[i] = i ;
        }
    }

    int findUParent(int node){
        if (parent[node] == node)
            return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if (ulp_u == ulp_v) return ;
        if (rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v ;
        }
        else if (rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u ;
        }
        else {
            parent[ulp_v] = ulp_u ;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if (ulp_u == ulp_v) return ;
        if (size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v ;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u ;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// Idea is to make use of disjoint set as the graph seems to be changing
// continuously, The idea is to consider all 1 values as individual sets. 
// Traverse the matrix and do a union of all adjacent 1 vertices
// so we keep traversing and keep changing the number of components
// For every edge, we need to return the number of components 
// the idea is to map a cell to every node and connect the cells so as to make 
// the components, this is done using disjoint set union 
// for a node, we traverse in all four directions and try to see if the 
// adjacent component has the same parent or not, if they dont have the same 
// ultimate parent, you can decrease the number of components and join them using 
// disjoint set union, we keep track of cells visited and try to explore the edge
// which has not been visited

// TC = O(n*m) , every cell is visited once
// SC = O(n*m) , union 
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<vector<int>>vis(n,vector<int>(m,0));
        DisjointSet ds(n*m);
        
        vector<vector<int>>dir = {{1,0},{0,-1},{-1,0},{0,1}};
        int count = 0 ;
        vector<int>ans;
        for (auto x : operators){
            int r = x[0];
            int c = x[1];
            
            if (vis[r][c] == 1){
                ans.push_back(count);
                continue;
            }
            
            vis[r][c] = 1;
            count++;
            
            for (int i = 0 ; i < 4 ; i++){
                int nr = r + dir[i][0] ;
                int nc = c + dir[i][1] ;
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 1){
                    int node = r*m + c;
                    int adjN = nr* m + nc ;
                    if (ds.findUParent(node) != ds.findUParent(adjN)){
                        count --;
                        ds.unionBySize(node,adjN);
                    }
                }
            }
            ans.push_back(count);
        }
        return ans ;
    }
};
