// the idea is to store queue len at each level before pushing the child nodes onto the queue
// this way we can iterate level by level

func levelOrder(root *TreeNode) [][]int {
	var res [][]int
	if root == nil {
		return res
	}

	q := []*TreeNode{root}

	for len(q) > 0 {
		level_cnt := len(q)
		var temp []int
		for i := 0; i < level_cnt; i++ {
			node := q[0]
			temp = append(temp, node.Val)
			q = q[1:]

			if node.Left != nil {
				q = append(q, node.Left)
			}
			if node.Right != nil {
				q = append(q, node.Right)
			}
		}
		res = append(res, temp)
	}
	return res
}