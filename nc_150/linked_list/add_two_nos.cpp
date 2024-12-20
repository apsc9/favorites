// Idea : keep track of the carry for every sum, make sure you do it like : carry/10
// this will reset it on every iteration, this results to carry being reset everytime
// then keep on adding the new sum, as long as the there are pointers or carry
// keep traversing the pointers

// TC = O(m+N)
// SC = O(1)

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(-1);
    ListNode *ptr = dummy ;

    int carry = 0 ;
    while (l1 || l2 || carry ){
        int sum = (l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0) + carry ;
        
        carry = sum/ 10;
        int val = sum % 10;
        ptr -> next = new ListNode(val);
        ptr = ptr -> next ;
        if (l1) l1 = l1 -> next ;
        if (l2) l2 = l2 -> next ;
    }
    ListNode* res = dummy -> next;
    delete dummy;
    return res ;
}