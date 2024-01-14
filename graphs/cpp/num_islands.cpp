// Each island is a connected component, what we have to find is no. of disconnected components in the graph
// Approach 1 : DFS Traversal

int numIslands(vector<vector<char>>& grid) {
    int islands = 0 ;

    for(int i = 0 ; i < grid.size() ; i++){
        for(int j = 0 ; j < grid[0].size() ; j++){
            if (grid[i][j] == '1'){
                dfs(grid,i,j);
                islands++;
            }
        }
    }
    return islands ;
}


void dfs(vector<vector<char>>&grid, int i, int j){
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
        return ;

    if (grid[i][j]== '2' || grid[i][j] == '0')
        return ;

    grid[i][j] = '2';

    dfs(grid,i+1, j);
    dfs(grid,i, j-1);
    dfs(grid,i-1, j);
    dfs(grid,i, j+1);
}


// Approach2: BFS Traversal: The idea is to find the number of disconnected components

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size() , m = grid[0].size() ;
    int islands = 0 ;

    vector<vector<int>>dir = {{1,0},{0,-1},{-1,0},{0,1}};

    queue<pair<int,int>>q ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if (grid[i][j] == '1'){
                islands++;
                grid[i][j] = '0';
                q.push({i,j});

                while(!q.empty()){
                    auto u = q.front() ;
                    q.pop();

                    for(int k = 0 ; k < 4 ; k++){
                        int x = u.first + dir[k][0];
                        int y = u.second + dir[k][1];

                        if (x >= 0 && x < n && y >=0 && y < m && grid[x][y] == '1'){
                            grid[x][y] = '0';
                            q.push({x,y});
                        }
                    }
                }
            }
        }
    }
    return islands;
}

// TC = O(m*n)
// SC = O(m*n)