// Idea : idea is to simply keep changing the pointers as per the given values
// just keep track of the very first node so that you can return it at the end
// keep comparing different heads and keep on connecting them.
// TC = O(n+m)
// SC = O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* prev = new ListNode(-1);
        ListNode* orig = prev;

        ListNode *h1 = list1, *h2 = list2;

        while(h1 && h2){
            if(h1 -> val <= h2 -> val){
                prev -> next = h1 ;
                h1 = h1 -> next;
            } else {
                prev -> next = h2 ;
                h2 = h2 -> next;
            }
            prev = prev -> next;
        }
        if (h1) {
            prev ->next = h1 ;
        }
        if (h2) {
            prev -> next = h2;
        }
        return orig -> next;
    }
};