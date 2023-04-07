// Approach 1 : track the path from root to both the nodes, store it in a ds and compare the path , whererver it matches at the deepest level(farthest indes)
// that is the lowest common ancestor , but this requires additional space complexity to store the paths, Hence not prefereable
 
// Approach 2 : The idea is to make use of traversal on both the left and right subtrees , the values will only be returned if you find a node on either left 
// or right subtree , else null is returned 
// if for some node , both left and right subtree return non NULL , then that node is the lowest common ancestor

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || root == p || root == q)
        return root ;

    // check whether you can find any node on either left side or right side
    TreeNode* left = lowestCommonAncestor(root -> left,p ,q );
    TreeNode* right = lowestCommonAncestor(root -> right, p, q);

    if (left == NULL) return right; // if nothing can be found on the left side, return right
    else if (right == NULL) return left ; // if nothing found on the right side, return left
    else  // if on both the sides you have found something, return root
        return root;
}

// TC = O(N) , time to traverse all the nodes
// SC = O(N) , auxilary space