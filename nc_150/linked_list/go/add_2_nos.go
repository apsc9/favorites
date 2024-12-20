// idea : keep traversing while keeping track of the carry, add new nodes for new val
// TC = O(m + n)
// SC = O(1)

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	dummy := &ListNode{}
	ptr := dummy

	carry := 0
	for l1 != nil || l2 != nil || carry != 0 {
		sum := 0
		if l1 != nil {
			sum += l1.Val
		}
		if l2 != nil {
			sum += l2.Val
		}

		sum += carry
		carry = sum / 10
		val := sum % 10
		ptr.Next = &ListNode{Val: val}
		ptr = ptr.Next

		if l1 != nil {
			l1 = l1.Next
		}
		if l2 != nil {
			l2 = l2.Next
		}
	}
	return dummy.Next
}