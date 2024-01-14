// The idea is to keep track of all the vertices that have not been explored yet and cover them by making use of adjacency list
// we use queue here to explore vertices so its adjacent vertices can be visited first, whenever a vertex is visited, mark it visited in the 
// array and move on to the rest 

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int>visited(V+1,0);
    queue<int>q ;
    q.push(0);
    visited[0] = 1 ;
    vector<int>ans ;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(int v: adj[u]){
            if (visited[v] == 0){
                q.push(v);
                visited[v] = 1 ;
            }
        }
    }
    return ans;
}

// TC = O(V+E) ; V - vertices and E - edges
// SC = O(V) for storing in the queue
