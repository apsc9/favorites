// DFS : The idea is to make use of recSt arr which keeps track of all the visited nodes in that particular recursion 
// if you find a node that is visited as well as a part of recSt (current recursion stack) then  there is definitely a cycle
// At the end of current recursion, make sure you backtrack and unmark  the elements in the current stack
// marking nodes are a part of current recursion call only


bool isCyclic(int V, vector<int> adj[]) {
    vector<int>vis(V,0), recSt(V,0);
    
    for(int i = 0 ; i < V ; i++){
        if (vis[i] == 0){
            if (dfs(adj,i,vis,recSt)){
                return true ;
            }
        }
    }
    return false ;
}

bool dfs(vector<int>adj[], int s,vector<int>&vis, vector<int>&recSt){
    vis[s] = 1 ;
    recSt[s] = 1 ;
    
    for(auto u: adj[s]){
        if (vis[u] == 0 && dfs(adj,u,vis,recSt))
            return true ;
        else if (recSt[u] == 1) // if the node is visited and is also part of the same recursion call then its a cycle
            return true ;
    }
    
    recSt[s] = 0 ;
    return false ;
}

// There is a way we can save extra space used above by the 
// recSt , as we can make use of the visited array only to keep
// track of whether a node is in the path of current recursion or not
// and by the end of recursion , if we find that it is not
// we just put integer value 2 in its place

bool isCyclic(int V, vector<int> adj[]) {
    vector<int>vis(V,0);
    // to  keep track of the path in the same recursion call , we make use of int 2 
    // int 2 will denote that the node has been visited but isnt in the path for the 
    // current recursion call 
    
    for(int i = 0 ; i < V ; i++){
        if (vis[i] == 0 && dfs(i,adj, vis))
            return true ;
    }
    return false;
}

bool dfs(int s, vector<int>adj[], vector<int>&vis){
    vis[s] = 1 ;
    
    for(auto u: adj[s]){
        if (vis[u] == 0 && dfs(u,adj,vis))
            return true;
        else if (vis[u] == 1) // if node is vis and is already a part of the path, yes cyc
            return true;
    }
    
    // when all the adj nodes are traversed and still no cycle is found that contains that
    // node as a part of the cycle, then remove that node from the path list
    // we do that by putting int 2 in the visited array
    
    vis[s] = 2 ;
    return false ;
}

// TC = O(V+E)
// SC = O(V) , for recursion stack as well the depth of the tree


// BFS based method : The idea here is to make use of topological sort to find whether it has a cycle or not 
// first of all we assign the indegrees to all the nodes, then push the elements with indegree 0 onto the queue
// Idea is only those elements will be on the queue whose indegree is zero,
// if there is a cycle then there will be atleast one node whose indegree will never be zero , so it wont ever be on the queue
// we keep count of the number of elements on the queue, if it matches the number of vertices , then there is no cycle 
// in case of cycle it doesnt match the number of vertices


bool isCyclic(int V, vector<int> adj[]) {
    vector<int>indegree(V,0);
    
    for(int i = 0 ; i < V ;i++){
        for(auto x: adj[i]){
            indegree[x]++;
        }
    }
    
    
    // pushing the nodes with indegree 0 onto the queue
    queue<int>q ;
    for(int i = 0 ; i < V ; i++){
        if (indegree[i] == 0)
            q.push(i);
    }
    
    // lets now explore all the elements of the queue and try to remove them and see the impact on other's indegree
    
    int count = 0 ;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        count++; // keep track of the number of elements pushed onto the queue
        
        for(auto x: adj[node]){ // for all the removed elements, just update the indegree of their neighbours as well 
            indegree[x]--;
            if (indegree[x] == 0) // if indegree is 0 , push onto the queue
                q.push(x);
        }
    }
    if (count == V) return false ; // No cycle
    return true ; // if atleast one less count , then cycle as indegree of one node wont ever be zero
    
}

// Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.
// Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the in-degree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes).