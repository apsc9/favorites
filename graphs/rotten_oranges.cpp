// Idea : in one go, the orange will rot its adjacent neighbours (this takes one second)
// First we are calculating the number of fresh oranges , then for each iteration 
// we are seeing the rotten oranges and whatever possible are there initially they will rot the fresh oranges around them in all 4 directions
// so we take initially all the rotten oranges and put them in a queue, they will rot all their adjacent oranges in one second
// As we put all the initial rotten oranges into the queue, we will wait for it to be empty and wait for the next iteration of queue
// This way we can check if no fresh oranges are left, we can simply say it is num(iterations)-1 as the last iteration will have all the rotten ones only
// so that should not be counted

int orangesRotting(vector<vector<int>>& grid) {
    int fresh = 0 , cnt = 0 ;
    queue<pair<int,int>>q ;
    
    int n = grid.size() , m = grid[0].size();
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if (grid[i][j] == 1)
                fresh++;
            else if (grid[i][j] == 2)
                q.push({i,j});
        }
    }
    
    vector<vector<int>>dir = {{1,0},{0,-1},{-1,0},{0,1}};
    while(!q.empty()){
        int sz = q.size();
        cnt++;
        while(sz--){
            auto u = q.front();
            q.pop();
            
            for(int i = 0 ; i < 4 ; i++){
                int x = u.first + dir[i][0];
                int y = u.second + dir[i][1];
                
                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1){
                    q.push({x,y});
                    grid[x][y] = 2 ;
                    fresh--;
                }
            }
        }
    }
    
    return fresh == 0 ? cnt-1 : -1 ;
}

// TC = O(m*n);
// SC = O(m*n);