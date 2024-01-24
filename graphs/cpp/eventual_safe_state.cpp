// The idea is to relate it with cycle detection in a directed graph
// A node cant be in a safe state under 2 conditions:
// i. If it a part of cycle (because if it is part of cycle then there will
// not be terminal node, as definitely there will be an outgoing edge)
// ii. if a node is leading to a cycle

// 1st approach : use DFS to detect cycle in a directed graph
// the idea is : while trying to detect a cycle , if cycle isnt found
// we wont be able to reset that path node, if no cycle we would have
// set it while returning from the dfs call , so we eventually see 
// what are the nodes that are reset , whoever have their values set 
// will either form a cycle or lead to a cycle

// TC : same as dfs: O(V+E)
// SC : O(V) for extra space

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> vis(n,0), path(n,0);
    vector<int>safe ;

    for(int i = 0 ; i < n ; i++){
        if (vis[i] == 0)
            dfs(i,vis,path, graph);
    }
    for(int i = 0 ; i < n ; i++){
        if (path[i] == 0)
            safe.push_back(i);
    }
    return safe ;

}

bool dfs(int node, vector<int>&vis, vector<int>&path, vector<vector<int>>&graph){
    vis[node] =  1;
    path[node] = 1 ;

    for(auto u: graph[node]){
        if (vis[u] == 0){
            if (dfs(u,vis,path,graph))
                return true ;
        }
        else if (path[u] == 1)
            return true ;
    }
    path[node] = 0 ;
    return false;
}

// Approach 2 : Use BFS 
// Step 1: Reverse the edges 
// Step 2 : apply topological sort concept and find the order
// step 3 : sort the array and return

// why this works : we have a concept of indegree in topo sort 
// but here we want to see the terminal nodes (ie the node having no outgoing edge)
// if we reverse the edges , that same node will be the one with no incoming edge
// we keep applying the same concept of topological sort and keep reducing the 
// nodes while reducing the indegree, the nodes where indegree isnt zero , originally 
// will definitely have outgoing edges or the path that leads to outgoing edge

// TC : O(V+E) + O(VlogV) , in worst case all the nodes can be safe nodes
// SC : O(V+E)

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int>indegree(n,0);

    vector<vector<int>>graphR(n);

    // reverse the edges 
    for (int i = 0 ; i < n ; i++){
        for (auto x : graph[i]){
            // as of now , we have edge i -> x 
            // we need to make it x -> i 
            graphR[x].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    for (int i = 0 ; i < n ; i++){
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int>ans;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        ans.push_back(u);

        for (auto v : graphR[u]){
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}