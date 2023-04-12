//Approach 1: DFS -> the idea is to check for disconnected graph as well so  we check it node by node
// The idea is : for all the unvisited nodes, keep marking them as visted and keep checking the adjacent nodes for these nodes
// if adjacent node is not visited, then recurse for it again and if it is already marked as visited then check whether it is not a parent node
// WHy we check if this is a parent : because we are already marking its parent as visited in the recursion call, so in order to conclude that 
// it is a cycle, that already visited node is some node other than the parent

bool isCycle(int V, vector<int> adj[]) {
    vector<int>vis(V,0);
    
    for(int i = 0 ; i < V ; i++){
        if (vis[i] == 0){
            if (dfs(adj,i,vis,-1) == true)
                return true ;
        }
    }
    return false;
}

bool dfs(vector<int>adj[], int s, vector<int>&vis , int parent){
    vis[s] = 1 ;
    for(auto u : adj[s]){
        if (vis[u] == 0){ // if adjacent node is not already visited, recurse for the same
            if (dfs(adj,u,vis,s)) // here we are passing parent as parameter as well with every call
                return true ;
        } 
        else if (u != parent) // if the adjacent is already visited then make sure it is not a parent
            return true ; // if it is some other node than parent which was already visited, then it is a cycle
    }
    return false;
}

// Time Complexity: O(N + 2E) + O(N), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes. 
// In the case of connected components of a graph, it will take another O(N) time.

// Space Complexity: O(N) + O(N) ~ O(N), Space for recursive stack space and visited array.

######################################################################################################################################

// Approach 2: 
// BFS : The idea is same as above , the only difference being that instead of recursive calls to check the adjacent nodes, we  are making use of queue
// in dfs recursive calls , we used to pass parent as a parameter too, so here to replace that we will push the node along with its parent onto the queue
// start with the root and check for the adjacent elements whether they have been visited or not. If not, then mark them visited and put them on the queue 
// along with their parent, if adjacent is already visited, then check whether it is parent or not


bool isCycle(int V, vector<int> adj[]) {
    vector<int>vis(V,0);
    
    for(int i = 0 ; i < V ; i++){
        if (vis[i] == 0){
            if (bfs(adj,i,vis))
                return true ;
        }
    }
    return false;
}


bool bfs(vector<int>adj[],int s, vector<int>&vis){
    vis[s] = 1 ;
    queue<pair<int,int>>q ;
    q.push({s,-1}); // push onto the queue the node along with its parent
    
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for(auto u: adj[node]){
            if (vis[u] == 0){ // if the adjacent node has not been visited , put it on the queue
                vis[u] = 1 ; // mark it  visited
                q.push({u,node}); 
            }
            else if(u != parent) // if the adjacent node is visited already , just check that it shouldnt be the parent
                return true ; 
        }
    }
    return false ;
}

// Time Complexity: O(N + 2E) + O(N), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes. 
// In the case of connected components of a graph, it will take another O(N) time.

// Space Complexity: O(N) + O(N) ~ O(N), Space for queue data structure and visited array.