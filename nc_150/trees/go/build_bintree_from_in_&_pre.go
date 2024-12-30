// Idea : try to make use of the definition of inorder and preorder traversals
// from preorder you can get the root initially for every subtree as you start traversing
// All you need to do now is : find the index of the root in inorder traversal so that you can
// have separate left and right subtrees, this way you can recurse and construct the tree

func buildTree(preorder []int, inorder []int) *TreeNode {
	rootInd := 0
	return solve(preorder, inorder, &rootInd, 0, len(inorder)-1)
}

func solve(preorder []int, inorder []int, rootInd *int, left int, right int) *TreeNode {
	if left > right {
		return nil
	}

	pivot := left // to find the index of root in inorder
	for inorder[pivot] != preorder[*rootInd] {
		pivot++
	}

	*rootInd = *rootInd + 1
	newNode := &TreeNode{Val: inorder[pivot]}
	newNode.Left = solve(preorder, inorder, rootInd, left, pivot-1)
	newNode.Right = solve(preorder, inorder, rootInd, pivot+1, right)
	return newNode
}