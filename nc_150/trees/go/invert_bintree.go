// Just keep traversing the left and right nodes and
// swap the nodes as you go forward
// TC = O(n)
// SC = O(1)

func invertTree(root *TreeNode) *TreeNode {
	if root == nil {
		return root
	}

	invertTree(root.Left)
	invertTree(root.Right)

	tmp := root.Left
	root.Left = root.Right
	root.Right = tmp

	return root
}