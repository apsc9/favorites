// Idea : try to make use of the definition of inorder and preorder traversals
// from preorder you can get the root initially for every subtree as you start traversing
// All you need to do now is : find the index of the root in inorder traversal so that you can 
// have separate left and right subtrees, this way you can recurse and construct the tree

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int rootIndex = 0 ;
    return solve(preorder, inorder, rootIndex, 0, inorder.size()-1);
}

TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &rootIndex, int left, int right){
    if (left > right) return NULL;
    // now lets try to find the index in the inorder arr which is supposed to be root
    int pivot = left ; // pivot is used to find the root in inorder , go from L to R
    while(inorder[pivot] != preorder[rootIndex])
        pivot++;

    rootIndex++; // increment the root index as we have found the root for now
    TreeNode* newNode = new TreeNode(inorder[pivot]);
    // left subtree : left -> pivot - 1
    newNode -> left = solve(preorder, inorder, rootIndex, left, pivot-1);
    // right subtree : pivot + 1 -> right 
    newNode -> right = solve(preorder, inorder, rootIndex, pivot+1, right);
    return newNode;
}


