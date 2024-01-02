// the idea here is to store the shapes of islands and in order to do 
// that we make sure that for every island, we traverse in the same order
// when it comes to storing the island we make use of base coordinates 
// while traversal for that particular island is started, when all the 
// connected components are found and the traversal is complete, then we
// push that vector of coordinates on to a set, this is to avoid 
// any other island with the same shape(as they also will be having the
// same set of coordinates when base coordinates are used to find the
// combination), we make use of dfs for traversal in this one 
// finally the size of set gives the unique islands 

// SC = O(n*m) , due to vector and set size 
// TC =      n * m * log(n*m)         +     4 * n * m 
//      (for loop with set insertion)         (dfs)

int countDistinctIslands(vector<vector<int>>& grid) {
    int n = grid.size() , m = grid[0].size() ;
    vector<vector<int>>vis(n,vector<int>(m,0));
    
    
    set<vector<pair<int,int>>> s ;
    
    for (int i = 0; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if (grid[i][j] == 1 && vis[i][j] == 0){
                vector<pair<int,int>> vc ;
                dfs(i,j,vis,grid,vc,i,j);
                s.insert(vc);
            }
        }
    }
    return s.size();
}

void dfs(int row, int col, vector<vector<int>>&vis, vector<vector<int>>&grid, vector<pair<int,int>>&vc, int rowi, int coli){
    int n = grid.size() , m = grid[0].size();
    vis[row][col] = 1 ;
    vc.push_back({rowi-row, coli-col});
    
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
    for (int i = 0 ; i < 4 ; i++){
        int x = row + dir[i][0];
        int y = col + dir[i][1];
        
        if (x >=0 && x < n && y >= 0 && y < m && vis[x][y] == 0 && grid[x][y] == 1){
            dfs(x,y,vis,grid,vc, rowi,coli);
        }
    }
    
}