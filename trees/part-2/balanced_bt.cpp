// The idea is make use of postorder traversal and calculate the height of the left and right subtree while traversing
// we will make use of -1 to denote imbalanced tree , as soon as you get -1 , just stop and return -1 straightaway

bool isBalanced(TreeNode* root) {
    return height(root) != -1 ;
}

int height(TreeNode* root){
    if (!root) return 0 ;

    // check for the imbalance in the left subtree and if it is dont traverse further
    int left = height (root -> left);
    if (left == -1) return -1; // if 

    // check for the imbalance in the right subtree and if it is, dont traverse further 
    int right = height(root -> right); 
    if (right == -1) return -1;

    if (abs(left-right) > 1) return -1 ; // difference should not be more than one

    return 1+max(left,right); // in case of balanced tree, return the height 
}

// TC = O(N) , every node is traversed just once 
// SC= O(1) + O(H) , H is the height of the recursion stack 