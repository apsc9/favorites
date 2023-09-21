TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     if (root == NULL) return root;
     int curr = root -> val;
     if(curr < p -> val && curr < q -> val)
         return lowestCommonAncestor(root -> right, p, q);
     else if (curr > p -> val && curr > q -> val)
         return lowestCommonAncestor(root -> left, p, q);
     return root;
}
