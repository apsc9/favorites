// approach : Bottom up approach
// instead of calling depth for each child node, we return the height of current node using DFS
// if the subtree of the current node is balanced, the fn returns the height, else it returns -1

// In this approach, each node needs to be accessed only once, hence the time complexity is O(N)

func isBalanced(root *TreeNode) bool {
    if root == nil { return true}
    return height(root) != -1 
}

func height(node *TreeNode) int {
    if node == nil {return 0} ;

    left := height(node.Left)
    if left == -1 {
        return -1
    }

    right := height(node.Right)
    if right == -1 { return -1 }

    diff := left - right 
    if diff < 0 {
        diff = -diff
    }
    if diff > 1 { return -1 }
    return 1 + max(left, right)
}