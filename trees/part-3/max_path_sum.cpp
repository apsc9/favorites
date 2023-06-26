// Idea : the idea is simple ,to traverse both the left and right subtree and find the max sum possible in that subtree
// If we have a negative path contribution from that subtree, it is better to ignore it and move on with the other value.
// So what we do is traverse left and right subtree and while backtracking, try to find the max sum path :
// this is done by val = max(val, l+r+root -> val) ; but before this we have to make sure left and right contribution isnt -ve.
// If it is, then take zero instead. Handle the corner case where tree has only negative nodes.
// at every iteration of the left and right, return root -> val + max(l,r);

int maxPathSum(TreeNode* root) {
    int val = INT_MIN;
    solve(root, val);
    return val;
}

int solve(TreeNode* root , int &val){
    if (root == NULL) return 0;
    
    int l = solve(root -> left, val );
    int r = solve(root -> right, val);

    l = (l < 0) ? 0 : l ;
    r = (r < 0) ? 0 : r ;
    val = max(val, l+ r + root ->  val);
    return root -> val + max(l,r);
}

// TC = O(N) as all the nodes are traversed
// SC = O(N) as in worst case of a skewed tree, recursion stack can go till O(N) depth
