// idea : Idea is to find the node at the deepest level which is greater than or equal to the nodes
// we try to move wrt the curr value we are at, then if both the values are kind of in the opp
// direction wrt the current val, we have our answer
// TC = O(Height)

// Recursive approach :

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	if p.Val < root.Val && q.Val < root.Val {
		return lowestCommonAncestor(root.Left, p, q)
	} else if p.Val > root.Val && q.Val > root.Val {
		return lowestCommonAncestor(root.Right, p, q)
	} else {
		return root
	}
}

// Iterative approach
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {

	for root != nil {
		if p.Val < root.Val && q.Val < root.Val {
			root = root.Left
		} else if p.Val > root.Val && q.Val > root.Val {
			root = root.Right
		} else {
			break
		}
	}
	return root
}