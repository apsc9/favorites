// The idea is to make use of recursion , here dfs in order to traverse the entire graph (here in the form of adjacency list)
// Idea is to make the clone of the node as soon as you encounter them in a graph, while traversing through the adjacency list 
// check whether you already have the cloned node in the map or not , if yes simply return it else make use of recursion again to make their clone and 
// update the adjacency list of the clones with the clones only , return the initial cloned node you started from 
// or let the recursion do its magic

// Method 1: DFS
// TC = O(V+E) , V - vertices, E -edges
// SC = O(V+E) , Adjacency list 



unordered_map<Node*,Node*>mp;
Node* cloneGraph(Node* node) {
    if(node == NULL) return node;
    return dfs(node);
}

Node* dfs(Node* curr){
    Node* clone = new Node(curr -> val);
    mp[curr] = clone ;

    for(Node* x: curr -> neighbors){
        if (mp.find(x) != mp.end()){
            clone-> neighbors.push_back(mp[x]);
        }
        else 
            clone -> neighbors.push_back(dfs(x));
    }
    return clone;
}

// Method 2 : BFS 
// Idea is to make use of bfs traversal in order to achieve the same thing
// when you find an initial node, make a clone of it and push it to the queue
// pop elements one by one from the queue and make sure that all their neighbours have their clones created 
// just link the neighbours with their respective clones and return the inital element(node)

// TC = O(V+E)

Node* cloneGraph(Node* node) {
    if (node == NULL) return node ;

    unordered_map<Node*, Node*>mp ;
    Node* clone = new Node(node -> val);
    mp[node] = clone ;

    queue<Node*>q ;
    q.push(node); // push the original ones onto the queue
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        for(auto x: curr -> neighbors){
            if (mp.find(x) == mp.end()){ //if a clone hasnt been created, create one
                //Node* temp = new Node(x -> val);
                mp[x] = new Node(x -> val);
                q.push(x) ; // push the node with no clone onto the queue
            }

            mp[curr]-> neighbors.push_back(mp[x]); // if it is in map, push it to the adjacency list
        }
    }
    return clone ;
}