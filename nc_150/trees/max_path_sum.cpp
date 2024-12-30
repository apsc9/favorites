// Idea is to check for every subtree whether that is the one with max sum
// else we try to find the maximum val returning subtree between the left and right
// this is because if root of some subtree has to be included in the path of max, then 
// either the left or the right can be taken, not both, this is the reason we return what we return
// TC = O(n)
// SC = O(height)

int maxPathSum(TreeNode* root) {
    int res = INT_MIN;
    solve(root, res);
    return res ;
}

int solve(TreeNode* root, int &res){
    if (root == NULL) return 0 ;

    int l = max(0,solve(root -> left, res));
    int r = max(0,solve(root -> right, res));

    // try to see if the current subtree could be the one with max val
    // to do this, we will take the sum of all three: root + left + right

    res = max(res, root -> val + l + r);
    return root -> val + max(l,r) ; 
    // if you are returning something which includes the root in the path to max
    // then you can only take either left or right
}