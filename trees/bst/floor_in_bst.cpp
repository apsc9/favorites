// the idea is similar to ceil in a bst , we just need to find a value 
// that is smaller than or equal to the given value

int floor(Node* root, int x) {
    // Code here
    int floor = -1 ;
    if (root == NULL) return floor ;
    
    Node* curr = root ;
    while(curr){
        if (curr -> data == x)
            return curr -> data;
        if(curr -> data < x){
            floor = curr -> data;
            curr = curr -> right ;
        }
        else 
            curr = curr -> left ;
    }
    return floor;
}

// TC = O(logN)
// SC = O(1)