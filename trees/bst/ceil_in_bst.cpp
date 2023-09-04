// the idea is to keep traversing the tree as per the given value
// in order to find the value just greater than or equal to this val
// so when we encounter any val > given, we consider it as ceil 
// and the ceil is later on updated with the value closer to the given 
// one , directions while traversing are handled accordingly

int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    
    if (root == NULL) return -1;
    int ceil = -1 ;
    
    Node* curr = root ;
    while(curr){
        if (curr -> data == input){
            ceil = curr -> data ;
            return ceil ;
        }
        else if (curr -> data > input){
            ceil = curr -> data ;
            curr = curr -> left ;
        }
        else 
            curr = curr -> right ;
    }
    return ceil ;


    // Your code here
}

//TC = O(nlogn) as this is a BST