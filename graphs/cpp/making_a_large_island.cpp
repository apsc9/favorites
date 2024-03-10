class DisjointSet {
public:
    vector<int> rank, parent, size;
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

// Basically, we are checking the largest group of connected 1’s we can get by changing each 
// possible cell with the value 0 one at a time. As it is clear that the graph is 
// changing dynamically, so we will be using disjoint set data structure
// The first step is to connect the components having val 1, this way we will get 
// to know the components that we already have
// the next step is to keep exploring every 0 and seeing whether it can contribute
// to the max size component, 
// a cell is represented by two parameters i.e. row and column. 
// But to connect the cells as we have done with nodes, we need to first 
// represent each cell with a single number. So, we will number them 
// from 0 to n*m-1
// note that we map each cell to a node respectively 
// using which the components can be connected, we try to see the max size of the 
// component that can be formed, and return that  , we also need to handle the 
// case where there are no zeroes , 
// we will just run a loop from node number 0 to n*n and for each node number, 
// we will find the ultimate parent. After that, we will find the sizes of 
// those ultimate parents and will take the size of the largest one

// TC: O(N2)+O(N2) ~ O(N2)  Inside those nested loops, all the operations are taking 
// apparently constant time. So, O(N2) for the nested loop only

// SC: O(2*N2) This is for the two arrays i.e. parent array and size array of size N2 
// inside the Disjoint set.

class Solution {
private:
    bool isValid(int nr, int nc, int n){
        return nr >= 0 && nr < n && nc >= 0 && nc < n ;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        vector<vector<int>>dir = {{1,0},{0,-1},{-1,0},{0,1}};
        
        // step1 : connect the components having all 1s
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < n ; j++){
                if (grid[i][j] == 0) continue ;

                for (int k = 0 ; k < 4 ; k++){
                    int nr = i + dir[k][0];
                    int nc = j + dir[k][1];

                    if (isValid(nr,nc, n) && grid[nr][nc] == 1){
                        int node = i * n + j ;
                        int adjN = nr * n + nc ;
                        ds.unionBySize(node, adjN);
                    }
                }
            }
        }

        // step2 : lets try to see the max size of the component that can be 
        // formed, for this we make use of set to keep track of the ultimate parent
        // from which the size of the component can be calculated, 

        int mx = 0 ;
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < n ; j++){
                if (grid[i][j] == 1) continue ;
                set<int>components;
                for (int k = 0 ; k < 4 ; k++){
                    int nr = i + dir[k][0];
                    int nc = j + dir[k][1];

                    if (isValid(nr,nc, n) && grid[nr][nc] == 1){
                        components.insert(ds.findUParent(nr * n + nc));
                    }
                }
                int size_comp = 0 ;
                for (auto x : components){
                    size_comp += ds.size[x] ;
                }
                // add one here to take care of the curent 0 which will be 
                // converted to 1
                mx = max(mx, size_comp + 1);
            }
        }

        // edge case  : when all the cells are one 

        for (int cell = 0 ; cell < n*n ; cell++){
            mx = max(mx, ds.size[ds.findUParent(cell)]);
        }
        return mx;
    }
};