// idea : Idea is to find the node at the deepest level which is greater than or equal to the nodes
// we try to move wrt the curr value we are at, then if both the values are kind of in the opp
// direction wrt the current val, we have our answer
// TC = O(Height)

// Recursive approach : 
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) return root;
    int curr = root -> val ;

    if (p -> val < curr && q -> val < curr) // val is greater than both, go left
        return lowestCommonAncestor(root -> left, p, q);
    else if (p -> val > curr && q -> val > curr) // val is less than both, go right 
        return lowestCommonAncestor(root -> right, p, q);
    else  // both are on the opp sides (kind of)
        return root;
}

// Iterative approach: 
// same approach as above, just iteration over here

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while(root){
        int curr = root -> val ;
        if (p -> val < curr && q -> val < curr)
            root = root -> left; // go left if both the values are small
        else if (p -> val > curr && q -> val > curr)
            root = root -> right ;// both are greater, so need to go right
        else 
            break; // both are on the opp side/ one coincides with the root
    }
    return root;
}