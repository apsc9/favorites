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

func reorderList(head *ListNode) {
	if head == nil || head.Next == nil {
		return
	}
	// find the middle elem first
	slow, fast := head, head

	for fast.Next != nil && fast.Next.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}

	// now reverse the second half of the list
	prev := (*ListNode)(nil)
	curr := slow.Next

	for curr != nil {
		nxt := curr.Next
		curr.Next = prev
		prev = curr
		curr = nxt
	}
	slow.Next = nil

	// now try to merge the two lists
	h1, h2 := head, prev

	for h2 != nil {
		nxt1 := h1.Next
		h1.Next = h2
		h1 = nxt1

		nxt2 := h2.Next
		h2.Next = h1
		h2 = nxt2
	}
}