bool isValidBST(TreeNode* root) {
    return bst(root ,LONG_MIN ,LONG_MAX);
}
    
int bst(TreeNode* node ,long min ,long max){
    if (!node) return 1 ;
    if(node -> val <= min || node -> val >= max)
      return 0 ;
        
    return bst(node -> left ,min , node -> val)
        && bst(node -> right , node -> val , max);
}
