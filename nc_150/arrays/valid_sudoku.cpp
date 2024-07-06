// The idea is to simply check it in every row, every col and every block of 
// size 3x3, so we will use a set for each row, each col and each block
// now the tricky part is to navigate to the index of the block , we just have to
// figure out a way to reach the index of that block and check if an element 
// is already there or not

// TC = O(9x9) ;
// SC = O(9x9)* 3 ;

bool isValidSudoku(vector<vector<char>>& board) {
    vector<set<int>> row(9), col(9), square(9);

    for (int i = 0 ; i < 9 ; i++){
        for(int j= 0 ; j < 9 ; j++){
            if (board[i][j] == '.')
                continue ;

            int num = board[i][j] -'0';
            if (row[i].count(num) ||
                col[j].count(num) ||
                square[(i/3)*3 + j/3].count(num))
                return false;

            row[i].insert(num);
            col[j].insert(num);
            square[(i/3)*3 + j/3].insert(num);
        }
    }
    return true ;
}

// same approach using arrays:
bool isValidSudoku(vector<vector<char>>& board) {
    int row[9][9] ={0}, col[9][9] ={0} , square[9][9] ={0};

    for (int i = 0 ; i < 9 ; i++){
        for(int j= 0 ; j < 9 ; j++){
            if (board[i][j] == '.')
                continue ;

            int num = board[i][j] -'0'-1; // to adjust the index 
            if (row[i][num] ||
                col[j][num] ||
                square[(i/3)*3 + j/3][num])
                return false;

            row[i][num] = 1;
            col[j][num] = 1;
            square[(i/3)*3 + j/3][num] = 1;
        }
    }
    return true ;
}