// The idea is to divide the problem into 2 parts :
// the first one : search the node
// the second one : delete the node
// the idea is to look for the node and try to reorganise the node 
// once the val is found, and that is done by search 
// if val is less than key, search right 
// if val is more than key search left 
// idea is simply to find the inorder successor from the left subtree 
// and connect the right subtree to the right side of it, 
// just simply return left of the root
// handle the cases where either of the left or the right node is NULL

// TC = O(height) 
// SC = O(1) as no extra space has been used

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root ==NULL) return NULL ;
    if(root -> val == key)
        return func(root);

    TreeNode* curr = root ;
    while(curr){
        if (curr -> val < key){ // val is less than key so it will look towards the right
            if (curr -> right && curr -> right -> val == key){
                curr -> right = func(curr -> right);
                break;
            }
            else
                curr = curr -> right ;
        }
        else { // case where curr -> val > key , so it has to search left 
                if (curr -> left && curr -> left -> val == key){
                    curr -> left = func(curr -> left);
                    break;
                }
                else 
                curr = curr -> left ;
        }
    }
    return root ;
}

TreeNode* func(TreeNode* root){
    if (root -> left == NULL)
        return root -> right ;
    else if (root -> right == NULL)
        return root -> left ;

    TreeNode* temp = root -> left ;
    while(temp -> right)
        temp = temp -> right;
    temp -> right = root -> right ;
    
    return root -> left ;
}