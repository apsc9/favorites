// Idea : the idea is to pick the root from preorder array,
// store the indices as per the inorder array and take it root by root .i.e. find the index of that root
// for the left subtree, traverse with indices : start -> index -1 
// for the right subtree, traverse with indices : index+1 -> end
// then accordingly construct the tree and return the root for every subtree

int preidx = 0 ; // index for finding the root using preorder
unordered_map<int,int>m ;
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for(int i = 0 ; i < inorder.size(); i++){
        m[inorder[i]] = i; // storing indices as per their positions in the tree
        // this is done so that after picking up the root, we can find the number of elem
        // to the left of the root and the right of the root and construct a tree
    }
    return solve(0, inorder.size()-1, preorder, inorder);
}

TreeNode* solve(int start, int end, vector<int>& pre, vector<int>& in){
    if(start > end) return NULL ;
    TreeNode* root = new TreeNode(pre[preidx++]); 
    // picking up the root node from preorder array and try to construct the tree around it

    if (start == end) return root ; // if only one node there, just return it

    // now pick the index of the root which we have already stored in the map initially
    // now try to construct the left and right subtree

    int index = m[root -> val] ; // getting the index of the root

    root -> left = solve(start, index-1, pre, in);
    root -> right = solve(index+1, end, pre, in);
    return root ;
}

// Time Complexity: O(N)
// Assumption: Hashmap returns the answer in constant time.

// Space Complexity: O(N)
// Reason: We are using an external hashmap of size ‘N’.