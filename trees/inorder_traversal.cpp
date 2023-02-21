// I. Idea is to make use of recursion in order to solve this. First recursively visit the left child to reach the leaf node , print the value and then recursively do the same for the right node. If a node is pointing to null, return to its parent

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans ;
        solve(ans,root);
        return ans;
    }

    void solve(vector<int>&ans, TreeNode* node){
        if (node  == NULL)
            return ;

        solve(ans,node -> left);
        ans.push_back(node -> val);
        solve(ans, node -> right);
    }
}; 

// TC = O(N) 
// As every node is visited exactly once
// SC = O(N) 
// In worst case, the tree might be a skewed one ,hence the depth of recusrion stack might go till O(N).

// II. Idea is to make use of iterative method for inorder traversal. Problem here is that we dont have a way to go from node to its parent. It is to solve this we are using are using an explicit stack. While traversing insert the nodes in the stack so that the next node is always at the top of the stack.

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans ;
        stack<TreeNode*>s ; // stack is being used as the element pushed in the end has to taken out first
        TreeNode* curr = root ;
        while(curr || !s.empty()){ // handles base case where stack isnt empty or atleast one node is there to traverse
            if (curr){ // keep traversing towards the leaf until a leaf is reached
                s.push(curr);
                curr = curr -> left ;
            }
            else {// if its null, return to its parent
                curr = s.top();
                s.pop();
                ans.push_back(curr -> val);
                curr = curr -> right ;
            }
        }
        return ans;
    }
};

// TC = O(N) 
// As every node is visited exactly once
// SC = O(N) 
// In worst case, the tree might be a skewed one ,hence the depth of recusrion stack might go till O(N).


// III. Morris Traversal : 
// The idea is to make a threaded binary tree so that the rightmost node of the left subtree is connected to 
// the main parent of the left subtree.
// Threaded binary trees is what we call it as the right most node needs to be connected back as this is the only way 
// to track back as there is no other way of going back to the parent and in inorder traversal it is important to go back
// Mainly three cases arise here :
// 1. there is no left child for  a given node , in that case just take the value of that node
// 2. there is left node and also a left subtree  but it is not related to parent , so we connect the righmost node to the parent node of that subtreee 
// and again start traversal from the left child of parent
// 3. there is left node and the rightmost node of the left subtree is already connected to the parent so we will remove the extra thread we created and 
// move on to the right subtree while pushing the current node in the traversal list.
// TC = O(N) + O(N)
// SC = O(1)


vector<int> inorderTraversal(TreeNode* root) {
            vector<int>inorder ;
            TreeNode* curr = root ;

            while(curr){
                if (curr -> left == NULL){
                    inorder.push_back(curr -> val);
                    curr = curr -> right ;
                }
                else {
                    TreeNode* prev = curr -> left;
                    while(prev -> right && prev -> right != curr)
                        prev = prev -> right ;

                    if (prev -> right == NULL){
                        prev -> right = curr;
                        curr = curr -> left ;
                    }
                    else {
                        prev -> right = NULL;
                        inorder.push_back(curr -> val);
                        curr = curr -> right ;
                    }

                }
            }
            return inorder ;
}

