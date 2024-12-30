// Idea : just check from the root itself and then move on to the left and right subtrees
//also handle the case where left and right are valid 

func isSubtree(root *TreeNode, subRoot *TreeNode) bool {
    if root == nil { return false }

    return isSameTree(root, subRoot) || isSubtree(root.Left, subRoot) || isSubtree(root.Right, subRoot);
}

func isSameTree(root *TreeNode, subRoot *TreeNode) bool {
    if root == nil && subRoot == nil { return true }
    if root == nil || subRoot == nil || root.Val != subRoot.Val { return false }

    return isSameTree(root.Left, subRoot.Left) && isSameTree(root.Right, subRoot.Right)
}