// The idea is to make use of postorder traversal inorder to calculate the height of left and right subtree first before the node
// the idea is to keep calculating the height of the left and the right subtrees, once we have the heights at the current node, 
// we can calculate   both the height and diameter of the current node


int diameterOfBinaryTree(TreeNode* root) {
        int diam = 0  ;
        traverse(root,diam);
        return diam;
}

int traverse(TreeNode* root, int &diam){
    if (root == NULL) return 0 ;

    int l = traverse(root -> left, diam);
    int r = traverse(root -> right, diam);

    diam = max(diam, l+r);
    return 1 + max(l,r);
}

// Time Complexity: O(N) 
// Space Complexity: O(1) Extra Space + O(H) Recursion Stack space (Where “H”  is the height of binary tree )  