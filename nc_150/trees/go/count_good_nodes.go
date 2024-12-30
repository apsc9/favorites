// Idea : just keep traversing the subtree while keeping track of the maxVal for the current subtree

func goodNodes(root *TreeNode) int {
	mxVal, count := root.Val, 0
	solve(root, mxVal, &count)
	return count
}

func solve(node *TreeNode, mxVal int, count *int) {
	if node == nil {
		return
	}
	if node.Val >= mxVal {
		*count += 1
		mxVal = max(mxVal, node.Val)
	}

	solve(node.Left, mxVal, count)
	solve(node.Right, mxVal, count)

}