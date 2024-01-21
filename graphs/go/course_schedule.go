// Idea is to make use of dfs here , we first of all make the adjacency list from
// the given set of requirements, once we have that we can simply make use of the
// fact that if we have a cycle in the dependency list for the courses, we simply
// wont be able to meet the requirements, so the problem comes down to just
// detecting the cycle in a directed graph, we make use of dfs as a first approach here
// TC = O(V+E) , same as dfs
// SC = O(V) , for extra space used , rec stackt too in wc

func canFinish(count int, pre [][]int) bool {
	// adj matrix banao pehle
	adj := make(map[int][]int, count)
	// [1,0] means you need to take 0 before 1

	for _, iter := range pre {
		course, req := iter[0], iter[1]
		adj[course] = append(adj[course], req)
	}

	vis := make([]int, count)

	for i := 0; i < count; i++ {
		if vis[i] == 0 && loopon(i, vis, adj) {
			return false
		}
	}
	return true
}

func loopon(node int, vis []int, adj map[int][]int) bool {
	vis[node] = 1

	for _, u := range adj[node] {
		if vis[u] == 0 && loopon(u, vis, adj) {
			return true // if loop is here
		} else if vis[u] == 1 {
			return true
		}
	}
	vis[node] = 2
	return false
} 