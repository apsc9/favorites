// the idea is to keep track of the max diam so far while traversing the 
// left and right subtree, this might not pass through the root, so we need to keep track all the time
// diam is sum of heights of the left and the right subtrees. Hence dfs based approach can be used to
// calc the height of each subtree while keeping track of max diam

int diameterOfBinaryTree(TreeNode* root) {
    int diam = 0;
    solve(root, diam);
    return diam ;
}

int solve(TreeNode* root, int &diam){
    if (root == NULL) return 0 ;

    int l = solve(root -> left, diam);
    int r = solve(root -> right, diam);
    diam = max(diam, l + r);
    return 1 + max(l,r);
}