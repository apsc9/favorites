//Problem Statement : https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem

//Idea is to traverse wherever possible , to cover all the four directions we have made 2 array corresponding to all the four directions


void solve(int i, int j, vector<vector<int>>&m,int n, vector<string>&ans, string moves,vector<vector<int>>&vis, int first[], int second[]){
    if (i == n-1 && j == n-1){
        ans.push_back(moves);
        return;
    }
    
    string s = "RDLU";
    
    for(int k = 0 ; k < 4 ; k++){
        int x = i+first[k], y = j+second[k];
        if (x >= 0 && y >= 0 && x < n && y < n && !vis[x][y] && m[x][y] == 1){
            vis[i][j] = 1;
            solve(x,y,m,n,ans, moves+s[k],vis,first,second);
            vis[i][j] = 0 ;
        }
    }
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string>ans ;
    vector<vector<int>>vis(n,vector<int>(n,0));
    int first[] = {0,1,0,-1};
    int second[] = {1,0,-1,0}; // combination makes : RDLU
    
    if (m[0][0] == 1)
        solve(0,0,m,n,ans,"",vis,first, second);
    return ans ;
}