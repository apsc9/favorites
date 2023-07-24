// The idea is to simply swap the right part with the left part and vice versa. We make use of recursion in order to do that 
// What we do is keep traversing the tree and keep swapping its right and left children

void mirror(Node* root) {
    if (root == NULL) return ;
    
    mirror(root -> left);
    mirror(root -> right);
    
    swap(root -> left, root -> right);
}
    
// TC = O(N) as all the nodes have been traversed atleast once
// SC =O(N) due to call stack which in case of skewed tree might go till O(N)

