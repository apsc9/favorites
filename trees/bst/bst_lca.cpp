// The idea is simple, you have to find a point from where both the nodes
// are in opposite direction, and that is only possible when either both 
// the nodes are less than the current node or greater than the current node
// we are making use of the property of bst, and once we find a point at which
// one node is on the left side while the other is on the right side or the 
// the current node is one of the nodes, then we simply stop and return this

// TC = O(height) height of the bst is what we have to traverse while search
// SC = O(N) auxilary space

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) return root;
    int curr = root -> val;
    if(curr < p -> val && curr < q -> val)
        return lowestCommonAncestor(root -> right, p, q);
    else if (curr > p -> val && curr > q -> val)
        return lowestCommonAncestor(root -> left, p, q);
    return root;
}
