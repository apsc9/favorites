// Approach 1 : Brute force
// we are given a list of nodes and for every node we will try to find 
// its correct position and try to insert the node in the tree
// this will take O(N) time in case of a skewed tree
// SO time complexity in worst case can be O(n*n)

// Approach 2 : Using inorder traversal
// we know that inorder traversal of a bst gives all the elements in sorted
// order so we try to make use of that and construct a binary search tree
// using inorder and preorder traversal of a tree
// TC in that case will be : O(nlogn) + O(n) as time is required to sort
// the tree first and then make a tree which takes O(n) time

// Approach 3 : make use of the prop of bst 
// we keep track of only upper bound for every node, 
// while adding node to the left  ub becomes the val of the node
// while moving to the right, we make use of the bound set earlier, 
// we dont update the bound while moving right

// to undertand why we dont need a left bound here , try to dry run the code
// TC = O(N) && SC = O(1) if auxilary space isnt counted

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0 ;
    return solve(preorder, i, INT_MAX);
}

TreeNode* solve(vector<int>&A, int &i, int bound){
    if (i == A.size() || A[i] > bound) return NULL ;

    TreeNode* node = new TreeNode(A[i++]);
    node -> left = solve(A, i , node -> val);
    node -> right = solve(A, i, bound);

    return node ;
}



// Alternate method :
TreeNode* insertBST(TreeNode* root,int key)
{
    if(root==NULL)
    {
        return new TreeNode(key);
    }
    
    if(key<root->val)
    {
        root->left = insertBST(root->left,key);
    }
    else if(key>root->val)
    {
        root->right = insertBST(root->right,key);
    }
    
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode* root = new TreeNode();
    root=NULL;
    
    for(auto i=preorder.begin();i!=preorder.end();i++)
    {
        root=insertBST(root,*i);
    }
    
    return root;
}
