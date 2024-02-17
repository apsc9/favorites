// Approach 1: Dijkstra using priority queue :
// TC = ElogV , 
// E : number of edges, V is number of vertices
// Here the idea is to use minheap so that we can make use of the next closest vertex to 
// traverse next, in the meantime we try relaxing the edge as well and update the dist array

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int>dist(V);
    for(int i = 0 ; i < V ; i++)    
        dist[i] = 1e9 ;

    dist[S] = 0 ;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,S});

    while(!pq.empty()){
        int d = pq.top().first ;
        int node = pq.top().second ;
        pq.pop();

        for (auto x: adj[node]){
            int edgewt = x[1] ;
            int adjN = x[0] ;

            if (dist[adjN] > dist[node] + edgewt){
                dist[adjN] = dist[node] + edgewt;
                pq.push({dist[adjN], adjN});
            }
        }
    }
    return dist ;
}

// Approach 2 : Usint set instead of priority queue
// using set , we have an additional flexibility of deleting the {dist, node} pair from the set if an entry with 
// lesser distance can be found for the adjacent node, so in a way that would have helped but it also takes 
// logn complexity because of the set data structure

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    set<pair<int,int>>s ;\
    s.insert({0,S}); // contains {dist, node}

    vector<int>dist(V,1e9);
    dist[S] = 0 ;
    while(!s.empty()){
        auto it = *(s.begin());
        int d = it.first ;
        int node = it.second ;
        s.erase(it);

        for(auto x: adj[node]){
            int adjNode = x[0];
            int edgewt = x[1] ;


            if (dist[adjNode] > d+ edgewt){
                // check whether that node was already there or not in the set
                if (dist[adjNode] != 1e9)
                    s.erase({dist[adjNode], adjNode});

                dist[adjNode] = d + edgewt ;
                s.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}
