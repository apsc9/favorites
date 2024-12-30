// Idea is to have a track of min and max values as we move down the subtree , 
// instead of using TreeNode you could have also use INT_MIN/INT_MAX or their long eqvt 
// as we move deeper , keep updating these min and max values 

func isValidBST(root *TreeNode) bool {
    return isValid(root, nil, nil)
}

func isValid(node *TreeNode, minNode *TreeNode, maxNode *TreeNode) bool{
    if node == nil { return true }
    if (minNode != nil  && node.Val <= minNode.Val) || (maxNode != nil && node.Val >= maxNode.Val) {
        return false 
    }
    return isValid(node.Left, minNode, node) && isValid(node.Right, node, maxNode)
}

// you can also use math.MinInt && math.MaxInt for the same 

func isValidBST(root *TreeNode) bool {
    return isValid(root, math.MinInt, math.MaxInt)
}

func isValid(node *TreeNode, minVal int, maxVal int) bool{
    if node == nil { return true }
    if (node.Val <= minVal) || (node.Val >= maxVal) {
        return false 
    }
    return isValid(node.Left, minVal, node.Val) && isValid(node.Right, node.Val, maxVal)
}