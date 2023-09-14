// The idea is to make use of property of BST that traversal gives 
// inorder results only, so we try to use the concept of 
// left node right to find the kth elem

// TC = O(N) as in worst case all the nodes might be traversed
// SC = O(N) in worst case recursion depth may go down

int kthSmallest(TreeNode* root, int k) {
    int res ;
    traverse(root,k,res);
    return res;
}

void traverse(TreeNode* root, int &k, int &res){
    if(!root) return ;
    if (root -> left)
        traverse(root-> left, k, res);

    k--;
    if(k == 0){
        res = root -> val;
        return ;
    }
    if (root -> right)
        traverse(root -> right, k, res);

}