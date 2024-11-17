// the idea is to make use of the fact that the rows are sorted , and also if we can see
// we will find that the entire 2 matrix can be thought of as a single matrix with rows concatenated
// one after the other. So we will treat it like a 1 d matrix is 
// we just need to map the index to the appropriate cell, which can be done by m :
// for index finding : 
// row = index / num_cols
// col = index % num_cols


bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n*m - 1;
        while(l <= r){
            int mid = l + (r-l)/2 ;
            int val = matrix[mid/m][mid%m];
            if (val == target) return true;
            else if(val < target)
                l = mid + 1;
            else 
                r = mid - 1;
        }
        return false ;
    }