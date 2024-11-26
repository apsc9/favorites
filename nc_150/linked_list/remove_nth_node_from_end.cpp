// Idea is : we take 2 pointers and maintain a distance of n between those 2 nodes, 
// that way we reach the end, we will have one of the pointers at the appropriate postition
// we can directly remove the node at that position and try to reconnect.
// TC = O(n)
// SC = O(1)

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *slow, *fast= head;
    for (int i = 0 ; i < n ; i++) fast = fast -> next;
    if (!fast) return head -> next;

    slow = head ;
    while(fast -> next){
        slow = slow -> next;
        fast = fast -> next;
    }
    slow -> next = slow -> next -> next;
    return head;
}