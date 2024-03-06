// The idea is to make use of Disjoint set in order to see if the nodes belong to the 
// same component. First we make sure that the edge weights are sorted in ascending order 
// so that the min weights can be picked, then we make use of the concept of disjoint set to 
// find if the 2 nodes belong to the same component, if they do, then we skip and move to the 
// other edge , else we consider that edge for mst and join them using unionByRank or unionBySize
// we check all the corresponding edges and calc the weight of min spanning tree

// TC = O(M+N) + O(MlogM) + O(M* 4* alpha * 2) 
// SC = O(N) + O(M)


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
        if (ulp_u < ulp_v){
            parent[ulp_u] = ulp_v ;
        }
        else if (ulp_u > ulp_v){
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

class Solution
{
public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //lets make a tuple having {wt, node, adjN}
        vector<pair<int,pair<int,int>>> edges;
        // O(N+E) 
        for(int i = 0 ; i < V ; i++){
            for (auto x: adj[i]){
                int adjN = x[0];
                int wt = x[1];
                int node = i;
                edges.push_back({wt, {node, adjN}});
            }
        }
        // O(MlogM)
        sort(edges.begin(), edges.end());
        
        DisjointSet ds(V);
        int ms_wt = 0 ;

        // O(M * 4 * alpha * 2)
        for(auto x : edges){
            int wt = x.first ;
            int u = x.second.first;
            int v = x.second.second;
            
            if (ds.findUParent(u) != ds.findUParent(v)){
                ms_wt += wt ;
                ds.unionBySize(u,v);
            }
        }
        return ms_wt ;
    }
};