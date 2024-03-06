// PRIMS : The idea is based on greedy approach simply , we start exploring
// the edges from a node, we see which one is the shortest one to take and
// traverse further, while marking the node as visited once all the nodes 
// adjacent to it/edges adjacent to it are explored, 
// to find the edge with min weight that needs to be taken, we make use
// of priority queue, Take a node, put the edge weights along with the 
// distances in the pq while marking them as visited
// TC = O(ELogE), at most pq can have all the edges and taking something out 
// from pq takes logn time , also for the adjacent nodes, the case will be same
// SC = O(E) , this is for storing the edges in the priority queue

int spanningTree(int V, vector<vector<int>> adj[])
{
    int sum = 0 ;
    vector<int>vis(V,0);

    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
    pq.push({0,0}); 
    // format : {dist, node}

    while(!pq.empty()){
        int dis = pq.top().first ;
        int node = pq.top().second;
        pq.pop();

        if (vis[node] == 1) continue ;
        vis[node] = 1 ;
        sum += dis ;

        for (auto x : adj[node]){
            int adjN = x[0] ;
            int wt = x[1] ;
            if (vis[adjN] == 0){
                pq.push({wt,adjN});
            }
        }
    }
    return sum ;
}
