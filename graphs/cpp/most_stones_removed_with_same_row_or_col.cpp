// The idea : we can assume that these types of stones, sharing either the 
// same row or column, are connected and belong to the same group.
// for each group we can remove all the stones leaving one stone intact. 
// So, we can conclude that at most we can remove (size of the group -1) 
// no. of stones from a group as we need to leave one stone untouched for each group.
// Now, if we can think of the stones as nodes, the different groups then 
// seem to be the different components of a graph
// To connect the component, we will convert the column number 
// to (column no. + total no. of rows) and perform the union of 
// row no. and the converted column number



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

// TC = O(n) , n : number of stones, given stones are traversed several times
// SC = O(2*(mrow + mcol)) ,  for parent and size array in disjoint set

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int mrow = 0, mcol = 0 ;
        for (auto x : stones){
            mrow = max(mrow, x[0]);
            mcol = max(mcol, x[1]);
        }
        DisjointSet ds(mrow+mcol+1);
        unordered_map<int,int> nodes;

        for (auto x : stones){
            int nodeRow = x[0];
            int nodeCol = x[1] + mrow + 1 ; // mapping col as well now
            ds.unionBySize(nodeRow, nodeCol); // this finds ultimate parents for nodes also
            nodes[nodeRow] = 1;
            nodes[nodeCol] = 1;
        }

        int cnt = 0;
        for (auto x : nodes){
            if (ds.findUParent(x.first) == x.first) // count no of ultimate parents
                cnt++;
        }
        return n - cnt ;
    }
};