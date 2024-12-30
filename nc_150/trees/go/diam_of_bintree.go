// the idea is to keep track of the max diam so far while traversing the
// left and right subtree, this might not pass through the root, so we need to keep track all the time
// diam is sum of heights of the left and the right subtrees. Hence dfs based approach can be used to
// calc the height of each subtree while keeping track of max diam

func solve(root *TreeNode, diam *int) int {
	if root == nil {
		return 0
	}

	l := solve(root.Left, diam)
	r := solve(root.Right, diam)
	*diam = max(*diam, l+r)
	return 1 + max(l, r)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func diameterOfBinaryTree(root *TreeNode) int {
	diam := 0
	solve(root, &diam)
	return diam
}