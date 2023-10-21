// Approach 1 : store the inorder and find the value just next to the given value,
// this will make TC = O(N) + O(logN) && SC = O(N)

// Approach 2 : while storing the inorder only look for a val greater than the given val
// this way tc = O(N) while SC = O(N)

// Efficient approach :
// The idea is to simply use a variable node to keep track of the successor, whenever we 
// see current value greater than the given value, we store it as a successor and try to
// find a value which is less than the value we have just stored so as to keep it 
// close to the given value, in case if given node val is less than the given node, we move
// right

// TC = O(height) , which can be O(N) in case of skewed tree
// SC = O(1) as no extra space has been used


Node * inOrderSuccessor(Node *root, Node *x)
{
    Node* succ = NULL ;
    
    while(root){
        if (x -> data >= root -> data)
            root = root -> right ;
        else{
            succ = root ;
            root = root -> left;
        }
    }
    return succ ;
}