// Recursive : push an element only once when current depth equals the size of the result
// push right elem first then left for a level, also take care of passing slices by reference else
// it will return an empty slice

func rightSideView(root *TreeNode) []int {
	var ans []int
	traverse(root, &ans, 0)
	return ans
}

func traverse(node *TreeNode, ans *[]int, currdep int) {
	if node == nil {
		return
	}
	if len(*ans) == currdep {
		*ans = append(*ans, node.Val)
	}

	traverse(node.Right, ans, currdep+1)
	traverse(node.Left, ans, currdep+1)
}

// BFS : Idea is to make use of queue only to push elements level wise and just pop out the
// first elem in the queue for that level , push from the right first as we need the right view

func rightSideView(root *TreeNode) []int {
	ans := make([]int, 0)
	if root == nil {
		return ans
	}

	q := []*TreeNode{root}

	for len(q) > 0 {
		n := len(q)
		for i := 0; i < n; i++ {
			node := q[i]

			if i == 0 {
				ans = append(ans, node.Val)
			}
			if node.Right != nil {
				q = append(q, node.Right)
			}
			if node.Left != nil {
				q = append(q, node.Left)
			}
		}
		q = q[n:]
	}
	return ans
}