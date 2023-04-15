// This can be possible only for DAG ( Directed acyclic graph) because in an undirected graph 
// we can’t decide which node will come first because there will be no direction, 
// and if there is a cycle topological order will not be possible

// 2 ->3 ->4 ->2 here if you can observe 

// 2 is appearing before 3, 3 is appearing before 4, 4 is appearing before 2 
// But 2 has already appeared before 4, So topological ordering will not be possible


// Approach1 : BFS 

//Function to return list containing vertices in Topological order. 
vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int>indegree(V,0);
    // assigning indegree to each vertex
    for(int i = 0 ; i < V ; i++){
        for(auto x:adj[i]){
            indegree[x]++;
        }
    }
    
    queue<int>q ;
    for(int i = 0 ; i < V ; i++){
        if (indegree[i] == 0)
            q.push(i);
    }
    
    vector<int>ans ;
    while(!q.empty()){
        int node = q.front();
        q.pop() ;
        ans.push_back(node);
        
        for(auto x:adj[node]){
            indegree[x]--;
            if (indegree[x] == 0)
                q.push(x);
        }
    }
    return ans;
}

// Time Complexity: O(N+E)
// Space complexity: O(N)+O(N)

// Approach2 : DFS 

// The idea here is to make use of visited array to keep track of what vertices have been visited, 
// and a atack to push the vertices in order , Ex: if case of u -> v , v is pushed first then u , 
// this way order can be maintained while finally taking out the element 


vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int>vis(V,0);
    stack<int>s ;
    
    for(int i = 0 ; i < V ; i++){
        if (vis[i] == 0){
            dfs(adj,i,vis,s);
        }
    }
    
    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

void dfs(vector<int>adj[],int u, vector<int>&vis ,stack<int>&s){
    vis[u] = 1 ;
    for(auto x :adj[u]){
        if (vis[x] == 0)
            dfs(adj,x,vis,s);
    }
    s.push(u);
}

// Time Complexity: O(N+E) 
// N = Number of node , E = Number of Edges
// Space Complexity: O(N) + O(N)
// Visited Array and Stack data structure. Both will be using O(N).
// Auxiliary Space Complexity:  O(N)
// Recursion call of DFS