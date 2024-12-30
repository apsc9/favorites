// Idea: keep traversing while keeping the count of current max, dont just pass the maxval by reference
// instead just pass it by value, that way the subtrees maxval will  be automatically taken care of

int goodNodes(TreeNode* root) {
    int mxval = INT_MIN ;
    int count = 0 ;

    solve(root, mxval, count);
    return count ;
}

void solve(TreeNode* node, int mxval, int &count){
    if (!node) return ;
    if (node -> val >= mxval){
        count += 1;
        mxval = max(node -> val, mxval);
    }
    
    solve(node -> left, mxval, count);
    solve(node -> right, mxval, count);
}