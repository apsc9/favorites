// Approach 1 : Using Recursion 
// We need to move in reverse postorder way here : Right , left , Root
// we make use of a reference variable to keep track of the right part  and ultimately set the left part to NULL
// now pev becomes current node so that it can be connected to the right of some left node
// Main challenge is to connect the left child to the right child and that is why we make use of a pointer called prev

class Solution {
public:
    TreeNode* prev = NULL ;
    void flatten(TreeNode* root) {
        if (root == NULL) return ;

        // we need to traverse to the right part first as our aim is to connect the left part from whatever part we 
        // are having from the end (constructing) from the end
        flatten(root -> right);
        flatten(root -> left);

        // the last part above is from the left subtree as some adjustments will be made and we will connect 
        // to the prev (which contains sorted part from the end)
        root -> right = prev ; // connect the right part to the previous we have already formed till now
        root -> left = NULL ; // we connect the left to null 
        prev = root ; // make previous point to the next node up in line
    }
};

// TC = O(N) as all the nodes are traversed
// SC = O(N) as in case of skewed tree , recursion depth might go to O(N)

// Approach 2 : Using Stack 
// Stack is mainly used to store the parent's right node. we want to make sure we deal with the left node first 
// and if we dont have a left node, we take the right node . Because of that we use  stack , we first push right node and then the left node
// idea is to connect the left node to the right part and left part to null , so we push right node first and then the left one

void flatten(TreeNode* root) {
    if(root == NULL) return ;
    stack<TreeNode*>s ;
    s.push(root);

    while(!s.empty()){
        TreeNode* curr = s.top();
        s.pop();

        if (curr -> right)
            s.push(curr -> right);
        if(curr -> left)
            s.push(curr -> left);

        if (!s.empty())
            curr -> right = s.top() ; // Note that we are not poppin out from the stack 

        curr -> left = NULL ;
    }
}

TC = O(N)  as the loop will cover every node once
SC = O(N) due to stack in the worst case of a skewed tree

// Approach 3 : Morris traversal 
// We will make use of the concept of threaded binary tree like we used in Morris traversal
// Here the rightmost part of the left subtree is connected to the right subtree  and we make sure that
// the left part is connected to the right subtree and left part is set to null , we then move to the newly set right part to see the same

void flatten(TreeNode* root) {
    TreeNode* curr = root ;
    while(curr){
        if (curr -> left){
            TreeNode* prev = curr -> left ;
            while(prev -> right)
                prev = prev -> right ;

            prev -> right = curr -> right ; 
            curr -> right = curr -> left ;
            curr -> left = NULL ;
        }
        curr = curr -> right ;
    }
}

// TC = O(N) as all the nodes are traversed 
// SC = O(1) as no extra space has been used