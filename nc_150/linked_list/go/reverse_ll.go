// Iteration : just try to connect backwards as we move fwd

func reverseList(head *ListNode) *ListNode {
	curr := head
	var prev *ListNode

	for curr != nil {
		nxt := curr.Next
		curr.Next = prev
		prev = curr
		curr = nxt
	}
	return prev
}

// Recursive approach : this is a little tricky as it looks to connect while
// traversing from the back to the front

func reverseList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	p := reverseList(head.Next)
	head.Next.Next = head
	head.Next = nil
	return p
}