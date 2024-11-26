// Idea is : we take 2 pointers and maintain a distance of n between those 2 nodes,
// that way we reach the end, we will have one of the pointers at the appropriate postition
// we can directly remove the node at that position and try to reconnect.
// TC = O(n)
// SC = O(1)

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	slow, fast := head, head

	for i := 0; i < n; i++ {
		fast = fast.Next
	}
	if fast == nil {
		return head.Next
	}

	for fast.Next != nil {
		slow = slow.Next
		fast = fast.Next
	}
	slow.Next = slow.Next.Next
	return head
}