// Approach 1 : top down approach 
// use defn of bal bt: diff b/w heights of two sub trees are not > 1 
// and both left and right subtree are also balanced. 
// Here for the current node, calling maxDepth for its left and right children has to access all of its
// children, thus complexity is O(N) and we do this for all the nodes in the tree. So TC = O(n^2)

bool isBalanced(TreeNode* root) {
    if (root == NULL) return true ;
    
    int left_depth = maxDepth(root -> left);
    int right_depth = maxDepth(root -> right);

    int diff = abs(left_depth-right_depth);
    
    return diff <= 1 && isBalanced(root -> left) && isBalanced(root -> right);
}

int maxDepth(TreeNode* node){
    if (node == NULL) return 0 ;

    int l = maxDepth(node -> left);
    int r = maxDepth(node -> right);

    return 1 + max(l,r);
}

// approach 2 : Bottom up approach
// instead of calling depth for each child node, we return the height of current node using DFS
// if the subtree of the current node is balanced, the fn returns the height, else it returns -1

// In this approach, each node needs to be accessed only once, hence the time complexity is O(N)
// which is better than the first one 

bool isBalanced(TreeNode* root) {
    if (root == NULL) return true ;
    return height(root) != -1 ;
}

int height(TreeNode* node){
    if (node == NULL) return 0 ;

    int left = height(node -> left);
    if (left == -1) return -1 ; // dont check further if unbal

    int right = height(node -> right);
    if (right == -1) return -1 ; // dont check further if unbal

    if (abs(left - right) > 1) return -1 ; // tree is unbal

    return 1 + max(left, right);
}
