// The idea is to make use of dfs or bfs in order to fill the grid with the 
// required colors , the only corner case is that if the initial color is the same 
// as the given color, then probably you dont need to do anything as only 
// the same colored elements could be changed and they would have already been 
// changed anyway so no need to do anything

// TC = O(m*n)
// SC = O(m*n)

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    vector<vector<int>>& grid(image);
    int init = grid[sr][sc];
    if (init == newColor) return grid;
    dfs(grid,sr,sc,init, newColor);
    return grid;
}

void dfs(vector<vector<int>>& grid, int i, int j , int init, int color){
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != init)
        return ;
        
    grid[i][j] = color;
    dfs(grid,i+1, j, init, color);
    dfs(grid,i, j-1, init, color);
    dfs(grid,i-1, j, init, color);
    dfs(grid,i, j+1, init, color);

}