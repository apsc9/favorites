// An intuitive approach is to keep track of the the random pointers for each of the nodes
// and use it while creating pointers and assign them the val from the hash table. But this leads
// to O(n) space complexity, 
// if we do not consider the space reversed for the output, then we could say that the algorithm 
// does not consume any additional memory during the processing, i.e. O(1) space complexity

Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*>m;
    Node* ptr = head;
    while(ptr){
        m[ptr] = new Node(ptr -> val);
        ptr = ptr -> next;
    }

    ptr = head;
    while(ptr){
        m[ptr]-> next = m[ptr-> next];
        m[ptr] -> random = m[ptr -> random];
        ptr = ptr -> next;
    }

    return m[head];
}


// we can though use a hack: just associate a duplicate node with every original node in the list, 
// this way we dont need extra space to keep track of the new nodes
// Approach is :
// 1. create dup nodes wrt each node
// 2. connect the random ptrs for the dup nodes
// 3. separate the 2 lists 
// TC = O(n)
// SC = O(1)

Node* copyRandomList(Node* head) {
    Node *curr = head;

    // first make the dup of every node available
    while(curr){
        Node* nxt = curr -> next;
        curr -> next = new Node(curr-> val);
        curr -> next -> next = nxt;
        curr = nxt;
    }

    // now lets make connect the random pointers for the dup nodes
        
    curr = head ;
    while(curr){
        if (curr -> random)
            curr -> next -> random = curr -> random -> next;

        curr = curr -> next -> next ;
    }

    // now lets separate the 2 lists
    Node* deep = new Node(-1);
    Node* dummy = deep;
    curr = head ;

    while (curr){
        Node* nxt = curr -> next -> next;
        dummy -> next = curr -> next;
        dummy = curr -> next;
        curr -> next = nxt;
        curr = nxt;
    }
    return deep -> next;
}