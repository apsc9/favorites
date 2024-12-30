// approach 1: store the respective paths from root to both the nodes, wherever they match at the 
// deepest level(farthest index), that is the lowest common ancestor, but this needs extra space

// Approach 2 : use dfs 
// idea is to traverse both the left and right subtrees, the val will only be returned if you find a node 
// on the left or right subtree else null is returned
// if both left and right subtree return something, that is the lca 
// TC = O(N) , time to traverse all the nodes
// SC = O(N) , auxilary space

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || root == p || root == q)
        return root;

    TreeNode* left = lowestCommonAncestor(root -> left, p, q);
    TreeNode* right = lowestCommonAncestor(root -> right, p, q);

    if (left == NULL) return right ;
    else if (right == NULL) return left;
    else return root;
}