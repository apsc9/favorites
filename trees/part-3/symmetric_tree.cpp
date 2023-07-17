// The idea is simple, we just have to check whether there is mirroring around the root
// this can be done by comparing the children on the right side as well as the left side
// the only twist is that if you are considering the left child on the left subtree then you just 
// have to check the right child on the right subtree because that is what we need to check whether a mirror is formed or not
// we have to also handle the cases where node on any one side is null while it is not on the other side 

bool isSymmetric(TreeNode* root) {
    if(!root) return true ;
    return solve(root -> left, root -> right);
}

bool solve(TreeNode* r1, TreeNode* r2){
    if (r1 == NULL || r2 == NULL)
        return r1 == r2 ; // covers both the cases when one of them is null and the other one is not

    // if none of them is null, then check for the values and then try to see if they form the mirror
    // it is to check the mirror property that we use left child of one and the right of other

    return (r1 -> val == r2 -> val) && solve(r1 -> left, r2 -> right) && solve(r1 -> right, r2 -> left);
    // to check both the children of the nodes on the opposite sides of the mirror
}

// TC = O(N) as all the nodes are traversed 
// SC = O(N) as in case of skewed tree , the stack can go to O(N) depth 