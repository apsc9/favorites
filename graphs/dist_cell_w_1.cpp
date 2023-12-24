// The idea is to use bfs for the problem tweaking it a bit
// the only thing is now instead of going from 0 to 1 to find the distance
// we now go from 1 to 0 , this makes it easy for us to go to various 
// 0s which are at a certain distance from those 1s , so we can do it in
// a single instance for bfs based approach where we simply need to see 
// the distance to go from 1 to 0 while keeping track of what is visited
// and what is not yet, this is better than picking every 0 and
// using bfs to get the distance to 1 for each 0

// We are simply using bfs based approach here 
// TC here : O(n*m) , n*m + 4 *(n*m)
// SC here : O(n*m)+ O(n) , space for vis arr and O(n) for recursion

vector<vector<int>>nearest(vector<vector<int>>grid)
{
    int n = grid.size() , m = grid[0].size();
    
    vector<vector<int>>vis(n, vector<int>(m,0));
    vector<vector<int>>ans(n, vector<int>(m,0));
    queue <pair<pair<int,int>, int>>q ;
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if (grid[i][j] == 1){
                vis[i][j] = 1 ;
                q.push({{i,j},0});
            }
        }
    }
    
    vector<vector<int>> dir = {{1,0},{0,-1},{-1,0},{0,1}} ;
    while(!q.empty()){
        auto u = q.front() ;
        q.pop();
        int row = u.first.first ;
        int col = u.first.second;
        int dis = u.second ;
        
        
        ans[row][col] = dis ; // marking the final distance 
        
        
        for(int i = 0 ; i < 4 ; i++){
            int nx = row + dir[i][0] ;
            int ny = col + dir[i][1] ;
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0){
                vis[nx][ny] = 1 ;
                q.push({{nx,ny}, dis+1});
            }
            
        }
    }
    return ans ;
}