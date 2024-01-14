// Idea is to simply use dfs to traverse the whole grid and mark
// the nodes that are on the boundary or reachable from the boundary
// while traversing again , just count the nodes which cant be reached 
// from the boundary, we will use simple dfs/bfs in order to achieve this
// TC = O(m*n)
// SC = O(1)

int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size() , m = grid[0].size();
    int count = 0 ;
    // first column and last column
    for(int i = 0 ; i < n ; i++){
        if (grid[i][0] == 1)
            dfs(i,0,grid);
        if (grid[i][m-1] == 1)
            dfs(i,m-1,grid);
    }

    // first row and last row
    for(int j = 0 ; j < m ; j++){
        if (grid[0][j] == 1)
            dfs(0,j,grid);
        if (grid[n-1][j] == 1)
            dfs(n-1,j,grid);
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if (grid[i][j] == 1)
                count++;
        }
    }
    return count;
}

void dfs(int u, int v, vector<vector<int>>&grid){
    grid[u][v] = 2;
    int n = grid.size() , m = grid[0].size() ;
    vector<vector<int>>dir = {{1,0},{0,-1},{-1,0},{0,1}};

    for (int i = 0 ; i < 4 ; i++){
        int x = u + dir[i][0];
        int y = v + dir[i][1];

        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1)
            dfs(x,y,grid);
    }
}