// !st Approach BFS: the problem can be mapped to simply finding whether the cycle exits in a directed graph
// Based on the prerequisites, we can make adjacency list and indegree array 
// indegree of a node indicates how many courses are prerequisites for this particular course , 
// indegree = 0 indicated no prereuisites and hence that course can be taken, 
// when a course is taken it opens up the way for other course to be taken, hence indegree of other course is decreased and 
// that too is pushed onto the the queue if no prerequisites are left, 
// this way just count the number of courses that can be taken(elem on the queue) and compare with the number given 

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int>indegree(numCourses,0);
    vector<int>adj[numCourses];

    // making adjacency list and initializing indegree to have a clear view of the dependency 
    for(auto i : prerequisites){
        adj[i[1]].push_back(i[0]);
        indegree[i[0]]++;
    }

    queue<int>q ; // psuh all the courses with no prerequsites on the queue , indegree indicates prerequisites
    for(int i = 0 ; i < numCourses ; i++){
        if (indegree[i] == 0)  
            q.push(i);
    }
    int count = 0 ;
    while(!q.empty()){ // keep counting the elements on the queue and updating the adjacents' indegree
        int node = q.front();
        q.pop();
        count ++ ;

        for(auto x: adj[node]){ // update the prerequisites for others if this course is taken
            indegree[x]--;
            if (indegree[x] == 0) // if no prerequisites, then push on to the queue
                q.push(x);
        }
    }

    return count == numCourses ; // count if finally all the course taken equals the total number of courses or not 
}

// TC = O(V+E);
// SC = O(V);


// 2nd approach : DFS : the same idea of finding the cycle in a directed
// graph is applicable here as well, here we make use of dfs in order to 
// determine whether all the courses can be taken or not 

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int>taken(numCourses,0);

    vector<vector<int>> seq(numCourses);
    for(auto x : prerequisites){
        seq[x[1]].push_back(x[0]);
    }

    for(int i = 0 ; i < numCourses; i++){
        if (!taken[i] && loopon(i,seq, taken))
            return false ;
    }
    return true ;
}

bool loopon(int course, vector<vector<int>>& seq, vector<int>&taken){
    taken[course] = 1 ;
    for (auto u : seq[course]){
        if (!taken[u] && loopon(u, seq, taken))
            return true;
        else if (taken[u] == 1)
            return true;
    }

    taken[course] = 2 ;
    return false;
}

