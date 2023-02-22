// I. Recursive :
// Idea is simple, traverse the node first, go left and then go right

vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans ;
        solve(root,ans);
        return ans;
}

void solve(TreeNode* root,vector<int>&ans){
        if (root == NULL)
            return ;

        ans.push_back(root -> val);
        solve(root -> left,ans);
        solve(root -> right,ans);
}

TC = O(N)
SC = O(N)

// II. Using stack :

// When we visit a node, we print its value, and then we want to visit the left child followed by the right child. 
//The problem is that there is no way that we can move from a child to a parent. To solve this problem, we use an explicit stack data structure.
// While traversing we can insert node values to the stack in such a way that we always get the next node value at the top of the stack


vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>s ;
        TreeNode* curr = root;
        while(curr || !s.empty()){
            if(curr){
                ans.push_back(curr -> val);
                s.push(curr);
                curr = curr -> left;
            }
            else {
                curr = s.top();
                s.pop();
                curr = curr -> right ;
            }
        }
        return ans;
    }

TC = O(N)
SC = O(N)

// III. Morris Traversal : 
// The idea is to make a threaded binary tree so that the rightmost node of the left subtree is connected to 
// the main parent of the left subtree.
// Threaded binary trees is what we call it as the right most node needs to be connected back as this is the only way 
// to track back as there is no other way of going back to the parent and in preorder traversal it is important to go back so as to go to the right side
// Mainly three cases arise here :
// 1: When the current node has no left subtree, so nothing to be traversed on the left side, so simply print the value of the current node and move to the right of the current node.
// 2: When there is a left subtree and the right-most child of this left subtree is pointing to null, set the right-most child to point to the current node, print the current node value and move to the left of the current node.
// 3: When there is a left subtree and the right-most child of this left-subtree is already pointing to the current node. In this case we know that the left subtree is already visited so we need to reset the last node to NULL and move the current node to its right. 
// TC = O(N) 
// SC = O(1)

vector<int> preorderTraversal(TreeNode* root) {
            vector<int>preorder;
            TreeNode* curr = root ;

            while(curr){
                if (curr -> left == NULL){
                    preorder.push_back(curr -> val);
                    curr = curr -> right;
                }
                else {
                    TreeNode* prev = curr -> left ;
                    while(prev -> right && prev -> right != curr){
                        prev = prev -> right ;
                    }
                    if (prev -> right == NULL){
                        preorder.push_back(curr -> val);
                        prev -> right = curr ;
                        curr = curr -> left;
                    }
                    else {
                        prev -> right = NULL;
                        curr = curr -> right ;
                    }
                }
            }
            return preorder ;
    }