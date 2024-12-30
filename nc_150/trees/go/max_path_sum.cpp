// Idea is to check for every subtree whether that is the one with max sum
// else we try to find the maximum val returning subtree between the left and right
// this is because if root of some subtree has to be included in the path of max, then 
// either the left or the right can be taken, not both, this is the reason we return what we return
// TC = O(n)
// SC = O(height)

func maxPathSum(root *TreeNode) int {
    res := math.MinInt
    solve(root, &res)
    return res 
}

func solve(node *TreeNode, res *int) int {
    if node == nil { return 0 }

    l := max(0, solve(node.Left, res))
    r := max(0, solve(node.Right, res))

    *res = max(*res, node.Val + l + r);
    return node.Val + max(l,r)
}