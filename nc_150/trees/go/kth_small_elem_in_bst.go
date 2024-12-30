// Naive : use any tree traversal, store the ans in an array , sort it and return the reqd elem

// Better approach : Make use of inorder traversal
// inorder traversal of a bst returns the elem in sorted order, so it will be like
// from inorder traversal , the first elem return will be the smallest , then second smallest and so on
// Idea is to keep a pointer counting the number of items inorder traversal has returned so far
// TC = O(n)
// SC = O(h)

// use morris traversal for no extra space

func kthSmallest(root *TreeNode, k int) int {
	res := 0
	inorder(root, &k, &res)
	return res
}

func inorder(node *TreeNode, k *int, res *int) {
	if node == nil {
		return
	}

	inorder(node.Left, k, res)
	*k = *k - 1
	if *k == 0 {
		*res = node.Val
		return
	}
	inorder(node.Right, k, res)
}