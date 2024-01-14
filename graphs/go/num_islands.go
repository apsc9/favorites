// Approach 1 ;
// DFS : use dfs to find the connected components in the graph
// TC = O(n*m)
// SC = O(n*m) as in worst case there might be just a single component

func numIslands(grid [][]byte) int {
	islands := 0
	n := len(grid)
	m := len(grid[0])
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] == '1' {
				dfs(i, j, grid)
				islands++
			}
		}
	}
	return islands
}

func dfs(i, j int, grid [][]byte) {
	if i < 0 || i >= len(grid) || j < 0 || j >= len(grid[0]) {
		return
	}

	if grid[i][j] == '0' || grid[i][j] == '2' {
		return
	}

	grid[i][j] = '2'

	dfs(i+1, j, grid)
	dfs(i, j-1, grid)
	dfs(i-1, j, grid)
	dfs(i, j+1, grid)
}

// Approach 2 : BFS , use it to find the number of connected components in the graph

type pos struct {
	x int
	y int
}

func numIslands(grid [][]byte) int {
	islands := 0
	n := len(grid)
	m := len(grid[0])

	dir := [][]int{{1, 0}, {0, -1}, {-1, 0}, {0, 1}}

	queue := []pos{}

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] == '1' {
				grid[i][j] = '0'
				islands++
				p := pos{
					x: i,
					y: j,
				}
				queue = append(queue, p)

				for len(queue) != 0 {
					item := queue[0]  // remove first
					queue = queue[1:] // reassign to next

					for k := 0; k < 4; k++ {
						x, y := item.x+dir[k][0], item.y+dir[k][1]
						if x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1' {
							queue = append(queue, pos{x: x, y: y})
							grid[x][y] = 1
						}
					}
				}
			}
		}
	}
	return islands
}