// Aproach 1 : BFS --> Intution comes from brute force , i.e if a vertex is colored with one color then the adjacent will be having the other color
// make use of queue to put all the nodes whose color have to be checked and conclude finally 

bool isBipartite(vector<vector<int>>& graph) { 
    int V = graph.size() ;
    vector<int>color(V,-1); // all vertices are uncolored initially

    for(int i = 0 ; i < V ; i++){
        if (color[i] == -1){ // start from the first vertex and check 
            if (solve(i,V,graph,color) == false)
                return false;
        }
    }
    return true;
}

bool solve(int u, int V, vector<vector<int>>& graph, vector<int>&color){
    // we make use of queue to put the nodes where adjacent nodes have to be explored
    queue<int>q ; 
    color[u] = 0 ; // initially first node is colored as o 

    q.push(u);
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto x: graph[node]){ // checking adjacent nodes of this node
            if (color[x] == -1){ // if this node is not colored yet
                color[x] = !color[node]; // make sure to assign the opposite color to the currr node
                q.push(x); // push the adjacent onto the queue
            }
            else if (color[x] == color[node]) // if adjacent node has the same color as the curr
                return false; // return false
        }
    }
    // if no such case found with same color for adjacent nodes and all nodes are covered, return true
    return true ; 
}

// TC = O(V+E)
// SC = O(V) // for color array and also for the queue


// Approach2 : DFS --> idea is to simply check for all the uncolored nodes initially and then fill them with 
// a certain color and check the adjacent nodes , just pass on the opposite color to the adjacent nodes 

bool isBipartite(vector<vector<int>>& graph) { 
    int V = graph.size() ;
    vector<int>color(V,-1);

    for(int i = 0 ; i < V ; i++){
        if (color[i] == -1){
            if (dfs(i,0,graph,color) == false)
                return false ;
        }
    }
    return true;
}

bool dfs(int node, int col, vector<vector<int>>&graph, vector<int>&color ){
    color[node] = col ;

    for(auto x: graph[node]){
        if (color[x] == -1){
            if (dfs(x, !col,graph,color) == false)
                return false;
        }
        else if (color[x] == color[node])
            return false;
    }
    return true ;
}

// Time Complexity: O(V + 2E), Where V = Vertices, 2E is for total degrees as we traverse all adjacent nodes.
// Space Complexity: O(3V) ~ O(V), Space for DFS stack space, colour array and an adjacency list.