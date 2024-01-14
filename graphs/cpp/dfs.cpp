// DFS is a traversal technique which involves the idea of recursion and backtracking. 
// DFS goes in-depth, i.e., traverses all nodes by going ahead, and when there are no further nodes to traverse in the current path, 
// then it backtracks on the same path and traverses other unvisited nodes. 

// The idea is to keep track of visited nodes and traverse the nodes that have not been visited, making use of recursion 
// you keep on exploring the adjacent nodes of every node that in the path till the path exists and then go back to the previous recursion call

// Time Complexity: For an undirected graph, O(N) + O(2E), For a directed graph, O(N) + O(E), 
// Because for every node we are calling the recursive function once, the time taken is O(N) and 2E is for total degrees as we traverse for all adjacent nodes.

// Space Complexity: O(3N) ~ O(N), Space for dfs stack space, visited array and an adjacency list.


vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int>ans ;
    vector<int>vis(V,0);
    dfs(0,adj,vis,ans);
    return ans ;
}

void dfs(int s, vector<int> adj[],vector<int>&vis, vector<int>&ans){
    vis[s] = 1 ;
    ans.push_back(s);
    
    for(auto x: adj[s]){
        if (vis[x] == 0)
            dfs(x,adj,vis,ans);
    }
}

// to make it work for disconnected graph as well , we try to iterate for every node the same call for dfs 

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int>ans ;
    vector<int>vis(V,0);
    for(int i = 0 ; i < V ; i++){
        if(vis[i] == 0)
            dfs(i,adj,vis,ans); // this way you can also count the connected components in a graph , just use a variable count & do ++
    }
    return ans ;
}
