// Naive : use any tree traversal, store the ans in an array , sort it and return the reqd elem

// Better approach : Make use of inorder traversal 
// inorder traversal of a bst returns the elem in sorted order, so it will be like 
// from inorder traversal , the first elem return will be the smallest , then second smallest and so on
// Idea is to keep a pointer counting the number of items inorder traversal has returned so far
// TC = O(n)
// SC = O(h)

// use morris traversal for no extra space 

int kthSmallest(TreeNode* root, int k) {

    int res; 
    inorder(root, k, res);
    return res ;
}

void inorder(TreeNode* node, int &k, int &res){
    if (node == NULL) return;
    
    inorder(node -> left, k, res);
    k--;
    if (k == 0){
        res = node -> val ;
        return ;
    }

    inorder(node -> right, k, res);
}