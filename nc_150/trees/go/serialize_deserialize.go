/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type Codec struct {
}

func Constructor() Codec {
	return Codec{}
}

// idea is to make use of level order traversal in order to traverse the tree (u can use any traversal)
// add a symbol for the null nodes, make sure everything is separated by commas
// TC = O(N)
// SC = O(N)

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
	if root == nil {
		return ""
	}

	result := ""
	queue := []*TreeNode{root}

	for len(queue) > 0 {
		current := queue[0]
		queue = queue[1:]

		if current == nil {
			result += "#,"
			continue
		}

		result += strconv.Itoa(current.Val)
		result += ","
		queue = append(queue, current.Left, current.Right)
	}
	return result
}

// the idea behind deserializing is to get the objects one by one from the stream
// initialize the first one as root , then push it onto the queue
// then for the subsequent elem as per the symbol inserted for NULL which is '#' here
// construct the tree, if the symbol is non-hash, then attach it to the left or right node
// and again push it onto the queue to make further subtrees.
// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
	if len(data) == 0 {
		return nil
	}

	nodes := strings.Split(data, ",")
	nodes = nodes[:len(nodes)-1] // remove the last elem
	// due to empty comma

	// if nodes[0] == "#" {
	//     return nil
	// }

	val, _ := strconv.Atoi(nodes[0])
	root := &TreeNode{Val: val}
	queue := []*TreeNode{root}
	i := 1

	for len(queue) > 0 {
		current := queue[0]
		queue = queue[1:]

		// check for the left child
		if nodes[i] != "#" {
			val, _ := strconv.Atoi(nodes[i])
			current.Left = &TreeNode{Val: val}
			queue = append(queue, current.Left)
		}
		i++

		// Right child
		if nodes[i] != "#" {
			val, _ := strconv.Atoi(nodes[i])
			current.Right = &TreeNode{Val: val}
			queue = append(queue, current.Right)
		}
		i++
	}
	return root
}

/**
 * Your Codec object will be instantiated and called as such:
 * ser := Constructor();
 * deser := Constructor();
 * data := ser.serialize(root);
 * ans := deser.deserialize(data);
 */