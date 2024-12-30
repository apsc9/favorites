// Idea : we need to check whether from the root itself, it is the subtree ,then we move onto the left and 
// right children, then we simply check whether the two trees are the same or not 
// TC = O(m*n)

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == NULL) return false;
    if (isSameTree(root, subRoot))
        return true ;

    return isSubtree(root->left, subRoot) || isSubtree(root -> right, subRoot);
}

bool isSameTree(TreeNode* p, TreeNode* q){
    if (!p && !q) return true ;
    if (p == NULL || q == NULL || p-> val != q -> val) return false;

    return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
}

// Another approach : similar one, just a bit different to code :
// here we traverse in inorder fashion and we try to match the current node
// we maintain a global variable and return in case we find the match

bool ans = false ;

bool match(TreeNode* root, TreeNode* subroot){
    if (root && subroot){
        bool a = match(root -> left, subroot-> left);
        bool b = match(root -> right, subroot -> right);

        if (root -> val == subroot -> val && a && b){
            return true;
        } else 
            return false;
    } else if (root == NULL && subroot == NULL)
        return true ;
    else 
        return false;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    inorder(root, subRoot);
    return ans;
}

void inorder(TreeNode* root, TreeNode* subroot){
    if (root) {
        inorder(root -> left, subroot);
        bool res = match(root, subroot);
        if (res) ans = true;
        inorder(root -> right, subroot);
    }
}