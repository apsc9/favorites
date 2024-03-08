// Idea is to make use of disjoint set here 
// in order to connect n components, we need n-1 min edges but the catch is 
// they need to be from the graph only , so we need to count the extra edges
// as well here which can be used to connect the components of a graph
// Extra edge : if in a component, for the two nodes of an edge, we find that
// they both have the same ultimate parent, then that edge is said to be extra
// we do the iteration over all the edges, in order to find the extra
// Condition to be satisfied : extras >= num_components -1 

// TC = O(E* 4* alpha) + O(V * 4 * alpha)

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

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        
        DisjointSet ds(n);
        
        int extras = 0 ;
        for (auto x : edge){
            int u = x[0];
            int v = x[1];
            if (ds.findUParent(u) == ds.findUParent(v))
                extras++;
            else 
                ds.unionBySize(u,v);
        }
        
        int comp = 0 ;
        for (int i = 0 ; i < n ; i++){
            if (ds.findUParent(i) == i)
                comp++;
        }
        
        // to connect x number of components, we need x-1 edges
        int reqd = comp-1 ;
        if (extras >= reqd) return reqd ;
        return -1 ;
    }
};