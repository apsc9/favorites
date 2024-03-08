// using disjoint set : 
// we make use of the disjoint set properties here, as we are given the edges
// we first connect the graph, this is done using unionByRank or unionBySize
// once the graph is connected with whatever edges we were given, we find the
// number of components , using the concept that in single component, all the 
// nodes have the same ultimate parent , and the ultimate parent is the only node
// with parent[i] = i , so we just simply count the total number of ultimate parents
// this gives the number of connected components

// TC = O(n^2 * 4 * alpha) + o(n)
// SC = O(3*n)

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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);

        // lets make the components first
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < n ; j++){
                if (isConnected[i][j] == 1){
                    ds.unionBySize(i,j) ; 
                }
            }
        }

        int cnt = 0 ;
        for (int i = 0 ; i < n ; i++){
            if (ds.findUParent(i) == i)
                cnt++;
        }
        return cnt;
    }
};