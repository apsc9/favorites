// just swap the nodes as you keep traversing towards the left and right
// TC = O(n)

TreeNode* invertTree(TreeNode* root) {
    if (!root) return root;

    invertTree(root -> left);
    invertTree(root -> right);

    TreeNode* temp = root -> left;
    root -> left = root -> right;
    root -> right = temp ;

    return root;   
}