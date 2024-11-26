// The requirement is to merge the 2 lists with elements taken alternatively
// where first list is the first half and 
// the second list is the second half sorted in the reverse order

// approach we can take:
// 1. find the middle pointer from where we will find the reversed lists
// 2. reverse the second half of the original list, make sure you set the middle elem of 
//  the reversed list to null to avoid duplicates
// 3. merge the two lists
// TC = O(n)
// SC = O(1)


void reorderList(ListNode* head) {
    // find the middle elem first

    ListNode *slow = head, *fast = head;
    while(fast -> next && fast -> next -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    // Now slow will be the middle irrespective of the odd/even elem
    // now try to reverse the arr from the second half
    ListNode *prev = NULL, *curr = slow -> next ;
    while(curr){
        ListNode* nxt = curr -> next;
        curr -> next = prev;
        prev = curr ;
        curr = nxt ;
    }
    slow -> next = NULL; // to make sure that the first list has proper end

    // now try to merge the two lists 
    ListNode* h1 = head, *h2 = prev;
    while(h2){
        ListNode *nxt1 = h1 -> next;
        h1 -> next = h2;
        h1 = nxt1;

        ListNode* nxt2 = h2 -> next;
        h2 -> next = h1;
        h2 = nxt2;
    }


}