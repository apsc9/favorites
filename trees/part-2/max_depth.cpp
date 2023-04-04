// idea is to make use of recursion and find the height to left and right subtree , 
// simply add 1 to the max height obtained 

int maxDepth(TreeNode* root) {
        if (root == NULL) return 0 ;

        int left = maxDepth(root -> left);
        int right = maxDepth(root -> right);

        return 1 + max(left,right);
    }

// TC = O(N)
// SC = O(1) Extra Space + O(H) Recursion Stack space, where “H”  is the height of the binary tree.

// Approach 2 : the depth of the Binary Tree is the number of levels in the binary tree. 
// So, if we simply do a level order traversal on the binary tree and keep a count of the number of levels, it will be our answer.

int maxDepth(TreeNode* root) {
        int depth = 0 ;
        if (!root) return depth ;
        queue<TreeNode*>q ;
        q.push(root);

        while(!q.empty()){
            int n = q.size() ;
            depth++;
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);
            }
        }
        return depth ;
    }

// TC = O(N) as every node is traversed just once
// SC = O(N) as queue is used 