// Idea : try to find the max between the left and right subtree and consider the root, hence + 1

func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}

	l := maxDepth(root.Left)
	r := maxDepth(root.Right)

	return 1 + max(l, r)
}