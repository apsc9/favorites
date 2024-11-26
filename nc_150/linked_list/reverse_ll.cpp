// Iteration : the idea is to simply keep connecting backwards as we go forward and return the 
// elem at the end 

// TC = O(n)
// SC = O(1)

ListNode* reverseList(ListNode* head) {
    ListNode* curr = head ;
    ListNode *nxt, *prev = nullptr;
    
    while(curr){
        nxt = curr -> next ;
        curr -> next = prev;
        prev = curr ;
        curr = nxt;
    }
    return prev;
}

// Recursive approach : try implementing it, 
// TC = O(n)
// SC = O(1)

ListNode* reverseList(ListNode* head) {
    if (head == NULL || head -> next == NULL)
        return head;

    ListNode* p = reverseList(head -> next);
    head ->next -> next = head;
    head -> next = NULL;
    return p;
}