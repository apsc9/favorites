// max depth : has to be found from the root to the farthest node
// we will just try to find the max between the left and the right subtree

int maxDepth(TreeNode* root) {
    if (root == NULL) return 0 ;

    int l = maxDepth(root -> left);
    int r = maxDepth(root -> right);

    return 1 + max(l,r) ;
}