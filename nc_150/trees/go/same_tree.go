// Recursive solution: if both the trees are empty, they are identical . If only one tree is empty or the 
// values of the current nodes are diff, the trees are not identical. We can then traverse recursively
// TC = O(n)
// SC = O(Height)

func isSameTree(p *TreeNode, q *TreeNode) bool {
    if p == nil && q == nil {return true} 
    if p == nil || q == nil || p.Val != q.Val { return false }

    return isSameTree(p.Left, q.Left) && isSameTree(p.Right, q.Right)
}

// Iterative solution : 
// the idea is to make use of Q, and keep pushing elements in sequence on it , 
// keep popping and keep comparing like we did in recursive solution above 

func isSameTree(p *TreeNode, q *TreeNode) bool {
    qp := []*TreeNode{p};
    qq := []*TreeNode{q};

    for len(qp) != 0 && len(qq)!= 0 {
        node1 := qp[0]
        qp = qp[1:]

        node2 := qq[0]
        qq = qq[1:]

        if node1 == nil && node2 == nil {
            continue 
        }

        if node1 == nil || node2 == nil || node1.Val != node2.Val {
            return false
        }

        qp = append(qp, node1.Left, node1.Right)
        qq = append(qq, node2.Left, node2.Right)
    }

    return true ;
}