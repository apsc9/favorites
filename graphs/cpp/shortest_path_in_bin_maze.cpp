// Idea is to simply make use of bfs algo here as we are seeing nodes at a same distance from a given 
// node just like we see in case of usual bfs traversal, priority queue or dijkstra's algo is not required here
// as we dont have varying distances over here , the idea to keep traversing and keep relaxing the distance 
// as we go and traverse the other coordinates
// Unlike BFS, DFS doesn't guarantee that we choose the shortest path first. 
// So, we might actually take the longest one first and end up finding a path based on the current state 
// of the visited set, and then finding and memoizing an incorrect result

// TC = O(8*n*m) , same as standard bfs
// SC = O(n*m) , extra space for dist array


int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size() , m = grid[0].size() ;
    vector<vector<int>>dist(n,vector<int>(m,1e9));
    dist[0][0] = 1 ;
    
    if (grid[n-1][m-1] != 0 || grid[0][0] != 0) return -1 ;
    queue<pair<int,int>>q ;
    q.push({0,0});

    vector<vector<int>>dir = {{1,0}, {1,-1}, {0,-1}, {-1,-1},{-1,0},{-1,1},
    {0,1}, {1,1}};

    while(!q.empty()){
        auto x = q.front(); q.pop();
        int row = x.first , col = x.second ;
        if (row == n-1 && col == m-1) return dist[row][col];

        for(int i = 0 ; i < 8 ; i++){
            int rnew = row + dir[i][0] ; 
            int cnew = col + dir[i][1] ;

            if (rnew >=0 && rnew < n && cnew >= 0 && cnew < m &&
            grid[rnew][cnew] == 0 && dist[rnew][cnew] > dist[row][col] + 1){
                q.push({rnew, cnew});
                dist[rnew][cnew] = dist[row][col] + 1 ;
            }
        }
    }
    return -1 ;
}