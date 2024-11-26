// Approach 1 : use map
// traverse the list twice, in the first iter: create a new node for every node in orig list
// in the second iter: connect the new nodes to their respective next and random ptrs
// time complexity: O(n), space complexity: O(n) (for hashmap)

func copyRandomList(head *Node) *Node {
	m := make(map[*Node]*Node)

	// store new nodes in a map
	ptr := head
	for ptr != nil {
		m[ptr] = &Node{Val: ptr.Val}
		ptr = ptr.Next
	}

	// connect the new nodes in a map
	ptr = head
	for ptr != nil {
		m[ptr].Next = m[ptr.Next]
		m[ptr].Random = m[ptr.Random]
		ptr = ptr.Next
	}
	return m[head]
}

// approach 2 : create nodes in between the originial nodes and connect them , then eventually
// separate the 2 lists after the random pointers are connected for every new node
// TC = O(n)
// SC = O(1)

func copyRandomList(head *Node) *Node {

	ptr := head
	// make the dup of every node just adjacent to it
	for ptr != nil {
		nxt := ptr.Next
		ptr.Next = &Node{Val: ptr.Val}
		ptr.Next.Next = nxt
		ptr = nxt
	}

	// now lets connect the random pointers for the newly connected dup nodes
	ptr = head
	for ptr != nil {
		if ptr.Random != nil {
			ptr.Next.Random = ptr.Random.Next
		}
		ptr = ptr.Next.Next
	}

	// lets separate the two lists now
	ptr = head
	copy := &Node{Val: -1}
	copyIter := copy

	for ptr != nil {
		nxt := ptr.Next.Next
		copyIter.Next = ptr.Next
		copyIter = ptr.Next
		ptr.Next = nxt
		ptr = nxt
	}
	return copy.Next
}

