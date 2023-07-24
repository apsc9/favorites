// Idea : simply check whether the property is followed or not, this is done recursively where we come down level by level and check for the same
// for every level keep track of the sum from its left and right child and try to compare against the prop
// TC =O(N) as all the nodes are traversed and SC = O(N) due to recursion space

int isSumProperty(Node *root){
    int sum = 0 ;
    if ((root == NULL) ||(root -> left == NULL && root -> right == NULL))
        return 1 ; // if it is NULL or a leaf node, then it follows the prop
        
    if(root -> left)
        sum += root -> left -> data ;
        
    if(root -> right)
        sum += root -> right -> data ;
        
    return (sum == root -> data) && isSumProperty(root -> left) && isSumProperty(root -> right);
}
// The first part of this problem dealt with checking whether the tree followed the child sum prop or not, in this second part
// we need to convert the tree so that it follows the child sum prop

void reorder(TreeNode* root){
    if (root == NULL) return ;
    int child = 0 ;

    if (root -> left)
        child += root -> left -> data ;

    if (root -> right)
        child += root -> right -> data ;

    if (child >= root -> data) // if sum of nodes is more, make root equal to the sum
        root -> data = child ;

    else { // if sum is less than the val of root , then make both the left and right child equal to the val of root so that prop is followed
        if (root -> left)
            root -> left -> data = root -> data ;
        if (root -> right)
            root -> right -> data = root -> data ;
    }

    reorder(root -> left);
    reorder(root -> right);

    // Reassignment after reordering 
    int tot = 0 ;
    if (root -> left) tot += root -> left -> data ;
    if (root -> right) tot += root -> right -> data ;
    if (root -> left || root -> right)
        root -> data = tot ; // reassignment to make sure that the prop is followed
}

// TC = O(N) as all the nodes are traversed atleast once
// SC = O(N) due to recursion stack 