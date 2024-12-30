// Idea is to have a track of min and max values as we move down the subtree , 
// instead of using TreeNode you could have also use INT_MIN/INT_MAX or their long eqvt 
// as we move deeper , keep updating these min and max values 

bool isValidBST(TreeNode* root) {
    return isVal(root, NULL, NULL);
}

bool isVal(TreeNode* node, TreeNode* minN, TreeNode* maxN){
    if (!node) return true;
    if (minN && node -> val <= minN -> val || maxN && node -> val >= maxN -> val)
        return false;

    return isVal(node -> left, minN, node) && isVal(node -> right, node, maxN);
}

// INT_MIN/MAX fail in one of the test cases so we have used long here :
bool isValidBST(TreeNode* root) {
    return isVal(root, LONG_MIN, LONG_MAX);
}

bool isVal(TreeNode* node, long minVal, long maxVal){
    if (!node) return true;
    if (node -> val <= minVal || node -> val >= maxVal)
        return false;

    return isVal(node -> left, minVal, node-> val) && isVal(node -> right, node-> val, maxVal);
}