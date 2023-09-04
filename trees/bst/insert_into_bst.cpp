// Approach: the idea is to simply find a position at the leaf node where the given node 
// can fit, though there are many combinations possible but just for the sake of 
// simplicity we are trying to insert the given value at a leaf where it follows 
// the props of a bst

// 1. Iterative Solution :

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == NULL) return new TreeNode(val);

    TreeNode* curr = root ;
    while(curr){
        if (curr -> val > val){
            if (curr -> left == NULL){// we have found a leaf 
                curr -> left = new TreeNode(val);
                break;
            }
            else 
                curr = curr -> left ;
        }
        else {
            if (curr -> right == NULL){
                curr -> right = new TreeNode(val);
                break;
            }
            else 
                curr = curr -> right ;
        }
    }
    return root ;
}

// TC = O(logn) ; height of bst 
// SC = O(1) ; no extra space is taken

// 2. Recursive solution

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (root -> val > val){
        root -> left = insertIntoBST(root -> left,val);
    }
    else {
        root -> right = insertIntoBST(root -> right, val);
    }
    return root ;
}

// TC = O(logn) , height of the bst 
// SC = O(n) , recursion depth can go to O(N) in worst case