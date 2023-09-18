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
