// DFS based approach : Idea is to simply fill the uncolored nodes
// initially with some color and check the color of adjacent nodes
// if same color is found in any of the adjacent nodes , ret false
// else color the adjacent node with the different colors and
// proceed till all the nodes are colored
// TC = O(V+E) , simply for dfs traversal
// SC = O(V) for extra space for colored array

func dfs(node, col int, color []int, graph [][]int) bool {
	color[node] = col

	for _, u := range graph[node] {
		if color[u] == -1 {
			if dfs(u, 1-col, color, graph) == false {
				return false
			}
		} else if color[u] == color[node] {
			return false
		}
	}
	return true
}

func isBipartite(graph [][]int) bool {
	n := len(graph)

	color := make([]int, n)

	for i := 0; i < n; i++ {
		color[i] = -1
	}

	for i := 0; i < n; i++ {
		if color[i] == -1 && dfs(i, 0, color, graph) == false {
			return false
		}
	}
	return true
}

// BFS based approach : just make use of queue to track the
// adjacent nodes and try to find if two adjacent nodes have
// the same color or not , just color all the adjacent nodes of
// a particular node with the opposite color of the node
// procedd and keep checking for the adjacent nodes
// TC = O(V+E) just like for bfs
// SC = O(V) for color array

func bfs(node int, color []int, graph [][]int) bool {
	queue := list.New()
	color[node] = 0 // fill a color to start with

	queue.PushBack(node)
	//fmt.println(queue.Front().Value)

	for queue.Len() != 0 {
		first := queue.Front().Value.(int)
		queue.Remove(queue.Front())

		for _, v := range graph[first] {
			if color[v] == -1 {
				color[v] = 1 - color[first]
				queue.PushBack(v)
			} else if color[v] == color[first] {
				return false
			}
		}
	}
	return true
}

func isBipartite(graph [][]int) bool {
	n := len(graph)

	color := make([]int, n)

	for i := 0; i < n; i++ {
		color[i] = -1
	}

	for i := 0; i < n; i++ {
		if color[i] == -1 && bfs(i, color, graph) == false {
			return false
		}
	}
	return true
}
