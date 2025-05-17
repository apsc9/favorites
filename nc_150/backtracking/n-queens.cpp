// the idea is to use brute force:
// for every col, check all the rows where a queen can be placed 
// move to the next col if found , then on the way back, backtrack and remove the queen
// from that position

// also you only need to check whether queen can be placed on the left side only
// including the diagonals

// this isnt an efficient implmntn as safe fn is taking O(3n)
// tc = O(n*3n) which could have been reduced

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n, string(n, '.'));
        
        solve(0, board, ans, n);
        return ans ;
    }

    void solve(int col, vector<string>&board, vector<vector<string>>&ans, int n){
        if (col == n){
            ans.push_back(board);
            return;
        }

        // for every col, check all the rows to find the approp posn
        for(int row = 0 ; row < n ; row++){
            if (safe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col+1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

    bool safe(int row, int col, vector<string>&board, int n){
        int nrow = row , ncol = col ;

        // check leftward diag
        while(row >= 0 && col >= 0){
            if (board[row][col] == 'Q') return false;
            row --;
            col --;
        }

        // check leftward horizontally
        row = nrow , col = ncol ;
        while(col >= 0){
            if (board[row][col] == 'Q') return false;
            col --;
        }

        // check downward diagonally left
        row = nrow , col = ncol ;

        while(row < n && col >= 0){
            if (board[row][col] == 'Q') return false;
            row ++;
            col --;
        }
        return true;
    }
};


// Efficient implementation : use hash instead of the safe function
// for lrow, upper as well as lower diagonal , this way there wont be a need to traverse thrice
// logic is : when you make a table and sum the row and col , it will be same for every col on 
// lower diag , 
// for upper diag : n-1 + col - row value turns out to tbe same
// so we can make a hash of size 2*n-1 and check whether any of the those have been traversed

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n, string(n, '.'));

        vector<int>lrow(n, 0) , upperDiag(2*n - 1, 0), lowerDiag(2*n - 1, 0);
        solve(0, board, ans, n, lrow, upperDiag, lowerDiag);
        return ans ;
    }

    void solve(int col, vector<string>&board, vector<vector<string>>&ans, int n, vector<int>&lrow, vector<int>&upperDiag, vector<int>&lowerDiag){
        if (col == n){
            ans.push_back(board);
            return;
        }

        // for every col, check all the rows to find the approp posn
        for(int row = 0 ; row < n ; row++){
            if (lrow[row] == 0 && 
                upperDiag[n-1 + col-row] == 0 && 
                lowerDiag[row+col] == 0)
            {
                board[row][col] = 'Q';
                lrow[row] = 1 ;
                upperDiag[n-1 + col - row] = 1;
                lowerDiag[row+col] = 1 ;
                solve(col+1, board, ans, n, lrow, upperDiag, lowerDiag);
                board[row][col] = '.';
                lrow[row] = 0 ;
                upperDiag[n-1 + col - row] = 0;
                lowerDiag[row+col] = 0 ;
            }
        }
    }
};