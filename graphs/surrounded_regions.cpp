// A key observation to make here is that the 'O's on the boundary or 
// the ones related to the boundary wont be convereted to 'X's as they
// dont have the all the surroundings as 'X' (one side is always empty)
// So we find the ones that are directly connected to the ones on the 
// boundary and for that we make use of dfs algo , we mark all of them 
// as visited and then traverse the matrix again to see all those 'O's
// which were not visited and then mark them as 'X' as ultimately they
// are the ones who are surrounded by 'X' on all the directions

// TC = O(n) + O(m) + O(4*n*m) ~= O(N*M)
// SC = O(N*M) , for the extra space used for vis array

private:
    void dfs(int x, int y, vector<vector<int>> &vis, vector<vector<char>>&mat){
        vis[x][y] = 1 ;
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<int>>dir = {{1,0},{0,-1},{-1,0},{0,1}};
        
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0 && mat[nx][ny] == 'O')
                dfs(nx,ny,vis, mat);
        }
        
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // int n = mat.size(), m = mat.size() ;
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i = 0 ; i < n ; i++){
            if (mat[i][0] == 'O' && vis[i][0] == 0)
                dfs(i,0,vis,mat);
            if(mat[i][m-1] == 'O' && vis[i][m-1] == 0)
                dfs(i, m-1, vis, mat);
        }
        
        for(int j = 0 ; j < m ; j++){
            if (mat[0][j] == 'O' && vis[0][j] == 0)
                dfs(0,j,vis,mat);
            if(mat[n-1][j] == 'O' && vis[n-1][j] == 0)
                dfs(n-1, j, vis, mat);
        }
        
        for(int i= 0; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if (mat[i][j] == 'O' && vis[i][j] == 0)
                    mat[i][j] = 'X';
            }
        }
        return mat;
    }