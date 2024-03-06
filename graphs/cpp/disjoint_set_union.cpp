// Disjoint set is used for dynamic graphs, the use case involves finding 
// whether the two node belong to the same component or not, this is 
// done in constant time using dsu 
// disjoint set gives us two functions : 
// 1. findparent()
// 2. union which can be union by rank or union by size


// union (u,v) :
// 1. find ultimate parent of u & v ; pu and pv 
// 2. find the rank of those ultimate parents
// 3. connect smaller rank to the larger rank always

// we connect smaller to larger rank one bcoz of 2 reasons, one to shrink the 
// length and the other to make sure that time taken to find the parent is 
// as minimal as possible 
// Findparent tc is O(4_alpha) ~= O(1) , same is the case with union by rank

// Both unionBySize and unionByRank have same time complexity = O(4*Alpha) == O(1)
#include <bits/stdc++.h>
using namespace std;
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
}

int main(){
#ifndef ONLINE_JUDGE
freeopen("input.txt", "r", stdin);
freeopen("output.txt", "w", stdout);
#endif

    DisjointSet ds(7);
    // either do unionbySize or unionByRank but not both at once
    // ds.unionByRank(1,2);
    // ds.unionByRank(2,3);
    // ds.unionByRank(4,5);
    // ds.unionByRank(6,7);
    // ds.unionByRank(5,6);


    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    // checkif 3 && 7 belong to the same component or not
    if (ds.findUParent(3) == ds.findUParent(7)){
        cout << "Same component" << endl;
    }
    else cout << "diff components" << endl;
    ds.unionBySize(3,7);

    if (ds.findUParent(3) == ds.findUParent(7)){
        cout << "Same component" << endl;
    }
    else cout << "diff components" << endl;

    return 0 ;
}