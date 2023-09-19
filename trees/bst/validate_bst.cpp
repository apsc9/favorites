// The idea is to simply make use of the property of binary search tree 
// where the root node is always greater than all the nodes on the left
// and less than all the nodes on the right
// we keep track of the range in which a node should fall in order 
// to be able to satisfy the property of a bst
// TC = O(N) as all the nodes have been traversed
// SC = O(N) due to auxilary stack space

bool isValidBST(TreeNode* root) {
    return validate(root, LONG_MIN, LONG_MAX);
}

int validate(TreeNode* node, long min, long max){
    if (!node) return 1 ;

    if (node -> val <= min || node -> val >= max)
        return 0 ;

    return validate(node -> left, min, node -> val) && 
        validate(node -> right, node -> val, max);
}