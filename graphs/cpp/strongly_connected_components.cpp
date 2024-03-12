// KosaRaju's ALgo to find the strongly connected components in the grap

// the idea is to somehow segregate the components, for that we reverse the graph because on scc there wont be any effect but the other 
// parts(sccs) get disconnected, so we reverse the whole graph instead of just reversing the edges between sccs and exploring it in lifo out as the 
//  node which was last, wont be able to reach the other ones except its own component because the the edges connecting to the other has been reversed.

// The nodes in the last SCC will finish first and will be stored in the last of the stack. After the DFS gets completed for all the nodes, 
// the stack will be storing all the nodes in the sorted order of their finishing time.

// by reversing the SCC-connecting edges, the adjacent SCCs become unreachable. Now, the DFS will work in such a way, 
// that in one DFS call we can only visit the nodes of a particular SCC. So, the number of DFS calls will represent the number of SCCs
// the algo mainly involves three steps:
// 1. sort the edges(nodes) in order of finishing time
// 2. Reverse the edges so as to disconnect the components
// 3. Do DFS traversal on the reversed graph , number of traversals will give the num of components

class Solution{
    private: 
    void dfs(int s, vector<vector<int>>&adj, vector<int>&vis , stack<int>&st){
        vis[s] = 1 ;
        for (auto x : adj[s]){
            if (!vis[x])
                dfs(x, adj, vis, st);
        }
        st.push(s); // finally push the element onto the stack at the end of that component traversal
        // this makes sure that the last node is on the top of stack
    }
    
    private:
    void dfs2(int node, vector<int>adj[] , vector<int>&vis){
        // this is for the traversal of the reversed graph, so that
        // we can have a count of the num of components
        vis[node] = 1 ;
        for (auto x : adj[node]){
            if (!vis[x])
                dfs2(x, adj, vis);
        }
    }
    
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int>vis(V,0);
        stack<int>st ;
        
        // O(V+E)
        // step 1: sort edges in terms of end time
        for (int i = 0 ; i < V ; i++){
            if (vis[i] == 0){
                dfs(i, adj,  vis, st);
            }
        }
        // step 2: reverse the edges 
        // O(V+E)
        vector<int>adjR[V];
        for (int i = 0 ; i < V ; i++){
            vis[i] = 0 ; // set it to zero again so as to be explored finally 
            
            for (auto x : adj[i]){
                // current edge : i -> x 
                // we will make : x -> i
                adjR[x].push_back(i); // reversing the edge
            }
        }
        
        // O(V+E)
        // do dfs on the reversed graph
        // num of scc will be equal to num of 
        int scc = 0 ;
        while(!st.empty()){
            int node = st.top() ; st.pop();
            if (vis[node] == 0){
                scc++;
                dfs2(node, adjR, vis);
            }
        }
        return scc ;  
    }
};
