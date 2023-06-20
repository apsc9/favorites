// Idea : The idea is to make use of the fact that in postorder, we have root stored at the end, so we just pick the root from the postorder and 
// try to pick up the elements from the inorder traversal and construct the tree 
// In order to construct the tree, just store the indices of inorder traversal in the map , this is just to pick the right index of the node, 
// So what we do is just pick the root from the preorder traversal and find its index, for inorder traversal we take the elements to the left of 
// this index for the left subtree and elements to the right for the right subtree, 
// In order to construct the proper subtree, we also need to change the indices for postorder subtrees as well
// for left subtree, we will take from postorder_start to number of elem on left of that index -1 
// ie (ps, ps + (index-is)-1 ) : this is done so that it picks the proper left and right nodes
// for right subtree, we take (ps+(index-is) , pe-1) as we already took the last elem as root 
// So this way iterating on both the sides, we will construct a tree


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (postorder.size() != inorder.size()) return NULL;
    unordered_map<int,int>m ;
    for(int i = 0 ; i < inorder.size(); i++){
        m[inorder[i]] = i ;
    }
    return solve(inorder,0,inorder.size()-1,postorder, 0, postorder.size()-1, m);
}

TreeNode* solve(vector<int>&io, int is, int ie, vector<int>&po , int ps, int pe, unordered_map<int,int>&m){
    if(is > ie || ps > pe) return NULL ;

    TreeNode* root = new TreeNode(po[pe]);
    int index = m[root -> val];

    int size = index - is ; //count the number of elements on the left of index 
    // so that they can be used for passing onto the argument the values of elements = on the 
    // left subtree and right subtree

    root -> left = solve(io, is, index - 1, po, ps , ps + size -1 , m); // number of elem on left and 
    // right in postorder is also passed to construct the subtree
    root -> right = solve(io, index+1, ie, po, ps+size , pe -1 , m); 
    return root ; 
}

// TC = O(N) As all the nodes are traversed
// SC = O(N) as we are using map to store all the elements of the tree